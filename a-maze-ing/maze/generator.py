from .pattern_42 import get_pattern_42
import random


class MazeGenerator:
    """Generate and store a maze."""

    def __init__(
        self,
        width: int,
        height: int,
        entry: tuple[int, int],
        exit: tuple[int, int],
        perfect: bool,
        seed: int | None = None,
    ) -> None:
        self.width = width
        self.height = height
        self.entry = entry
        self.exit = exit
        self.perfect = perfect
        self.seed = seed

        if width <= 0 or height <= 0:
            raise ValueError("Maze dimensions must be positive.")

        for name, (x, y) in (("ENTRY", entry), ("EXIT", exit)):
            if not (0 <= x < width and 0 <= y < height):
                raise ValueError(f"{name} is outside the maze bounds.")
        if entry == exit:
            raise ValueError("Entry and exit must be different.")        

        self.maze: list[list[int]] = [
            [15 for _ in range(width)]
            for _ in range(height)
        ]
        self.blocked_cells: set[tuple[int, int]] = get_pattern_42(width, height)

        if self.entry in self.blocked_cells:
            raise ValueError("Entry cannot be inside the '42' pattern.")
        if self.exit in self.blocked_cells:
            raise ValueError("Exit cannot be inside the '42' pattern.")

    def _get_neighbors(
        self,
        x: int,
        y: int,
    ) -> list[tuple[int, int]]:
        neighbors: list[tuple[int, int]] = []

        directions = [
            (0, -1),   # North
            (1, 0),    # East
            (0, 1),    # South
            (-1, 0),   # West
        ]

        for dx, dy in directions:
            nx = x + dx
            ny = y + dy

            if 0 <= nx < self.width and 0 <= ny < self.height:
                if (nx, ny) not in self.blocked_cells:
                    neighbors.append((nx, ny))

        return neighbors

    def _remove_wall(
        self,
        x1: int,
        y1: int,
        x2: int,
        y2: int,
    ) -> None:
        dx = x2 - x1
        dy = y2 - y1

        if dx == 1:          # East
            self.maze[y1][x1] &= ~2
            self.maze[y2][x2] &= ~8
        elif dx == -1:       # West
            self.maze[y1][x1] &= ~8
            self.maze[y2][x2] &= ~2
        elif dy == 1:        # South
            self.maze[y1][x1] &= ~4
            self.maze[y2][x2] &= ~1
        elif dy == -1:       # North
            self.maze[y1][x1] &= ~1
            self.maze[y2][x2] &= ~4

    def _generate_perfect(self) -> None:
        """Generate a fully connected maze without loops."""
        rng = random.Random(self.seed)

        visited: set[tuple[int, int]] = {self.entry}
        stack: list[tuple[int, int]] = [self.entry]

        while stack:
            x, y = stack[-1]

            neighbors = [
                cell
                for cell in self._get_neighbors(x, y)
                if cell not in visited
            ]

            if not neighbors:
                stack.pop()
                continue

            nx, ny = rng.choice(neighbors)

            self._remove_wall(x, y, nx, ny)
            visited.add((nx, ny))
            stack.append((nx, ny))

        walkable_cells = (self.width * self.height - len(self.blocked_cells))
        if len(visited) != walkable_cells:
            raise ValueError(
                "Maze cannot be fully connected with the current parameters."
            )

    def _has_wall(
        self,
        x1: int,
        y1: int,
        x2: int,
        y2: int,
    ) -> bool:
        dx = x2 - x1
        dy = y2 - y1

        if dx == 1:       # East
            return bool(self.maze[y1][x1] & 2)
        if dx == -1:      # West
            return bool(self.maze[y1][x1] & 8)
        if dy == 1:       # South
            return bool(self.maze[y1][x1] & 4)
        if dy == -1:      # North
            return bool(self.maze[y1][x1] & 1)
        return False

    def _get_removable_walls(
        self,
    ) -> list[tuple[int, int, int, int]]:
        walls: list[tuple[int, int, int, int]] = []

        for y in range(self.height):
            for x in range(self.width):
                if (x, y) in self.blocked_cells:
                    continue

                # Only check East and South to avoid recording the same wall twice.
                for nx, ny in ((x + 1, y), (x, y + 1)):
                    if nx >= self.width or ny >= self.height:
                        continue

                    if (nx, ny) in self.blocked_cells:
                        continue

                    if self._has_wall(x, y, nx, ny):
                        walls.append((x, y, nx, ny))
        return walls

    def _is_open_3x3(self, start_x: int, start_y: int) -> bool:
        """Check whether a specific 3x3 area is fully open."""

        # Check horizontal connections.
        for y in range(start_y, start_y + 3):
            for x in range(start_x, start_x + 2):
                if self._has_wall(x, y, x + 1, y):
                    return False

        # Check vertical connections.
        for y in range(start_y, start_y + 2):
            for x in range(start_x, start_x + 3):
                if self._has_wall(x, y, x, y + 1):
                    return False
        return True

    def _can_remove_wall(
        self,
        x1: int,
        y1: int,
        x2: int,
        y2: int,
    ) -> bool:
        """Check whether a wall can be safely removed."""
        if (x2, y2) not in self._get_neighbors(x1, y1):
            return False
        if not self._has_wall(x1, y1, x2, y2):
            return False

        cell1 = self.maze[y1][x1]
        cell2 = self.maze[y2][x2]

        self._remove_wall(x1, y1, x2, y2)

        min_x = min(x1, x2)
        max_x = max(x1, x2)
        min_y = min(y1, y2)
        max_y = max(y1, y2)

        for start_y in range(max_y - 2, min_y + 1):
            for start_x in range(max_x - 2, min_x + 1):
                if (
                    0 <= start_x <= self.width - 3
                    and 0 <= start_y <= self.height - 3
                    and self._is_open_3x3(start_x, start_y)
                ):
                    self.maze[y1][x1] = cell1
                    self.maze[y2][x2] = cell2
                    return False

        self.maze[y1][x1] = cell1
        self.maze[y2][x2] = cell2
        return True

    def _count_open_neighbors(self, x: int, y: int) -> int:
        """Count open connections from a cell."""
        count = 0

        for nx, ny in self._get_neighbors(x, y):
            if not self._has_wall(x, y, nx, ny):
                count += 1

        return count

    def _get_dead_ends(self) -> list[tuple[int, int]]:
        """Return all dead-end cells."""
        dead_ends: list[tuple[int, int]] = []

        for y in range(self.height):
            for x in range(self.width):
                if (x, y) in self.blocked_cells:
                    continue

                if self._count_open_neighbors(x, y) == 1:
                    dead_ends.append((x, y))

        return dead_ends

    def _reduce_dead_ends(self, rng: random.Random) -> None:
        """Reduce dead ends by opening additional safe connections."""
        for x, y in self._get_dead_ends():
            candidates: list[tuple[int, int]] = []

            for nx, ny in self._get_neighbors(x, y):
                if (
                    self._has_wall(x, y, nx, ny)
                    and self._can_remove_wall(x, y, nx, ny)
                ):
                    candidates.append((nx, ny))

            if candidates:
                nx, ny = rng.choice(candidates)
                self._remove_wall(x, y, nx, ny)

    def _ensure_open_corridor(self, x: int, y: int) -> None:
        """Ensure a required cell has at least two open connections."""
        neighbors = self._get_neighbors(x, y)

        target = min(2, len(neighbors))

        while self._count_open_neighbors(x, y) < target:
            candidates = [
                (nx, ny)
                for nx, ny in neighbors
                if self._can_remove_wall(x, y, nx, ny)
            ]

            if not candidates:
                raise ValueError(
                    "Unable to create required open corridor."
                )

            nx, ny = candidates[0]
            self._remove_wall(x, y, nx, ny)

    def _open_required_corridors(self) -> None:
        """Ensure the four corners and centre are open corridors."""
        centre = (
            (self.width - 1) // 2,
            (self.height - 1) // 2,
        )
        required = {
            (0, 0),
            (self.width - 1, 0),
            (0, self.height - 1),
            (self.width - 1, self.height - 1),
            centre,
        }

        for x, y in required:
            if (x, y) in self.blocked_cells:
                raise ValueError(
                    "The '42' pattern blocks a required corridor."
                )

            self._ensure_open_corridor(x, y)

    def _generate_non_perfect(self) -> None:
        """Generate a connected maze with multiple loops."""
        self._generate_perfect()
        rng = random.Random(self.seed)
        
        self._open_required_corridors()
        walls = self._get_removable_walls()
        if len(walls) < 2:
            raise ValueError("Maze is too small to create multiple loops.")
        rng.shuffle(walls)
        
        target_loops = max(2, len(walls) // 10)
        removed = 0

        for x1, y1, x2, y2 in walls:
            if self._can_remove_wall(x1, y1, x2, y2):
                self._remove_wall(x1, y1, x2, y2)
                removed += 1

            if removed >= target_loops:
                break

        if removed < 2:
            raise ValueError("Unable to create multiple valid loops.")
        
        self._reduce_dead_ends(rng)

    def generate(self) -> None:
        """Generate the maze."""
        self.maze = [
            [15 for _ in range(self.width)]
            for _ in range(self.height)
        ]

        if self.perfect:
            self._generate_perfect()
        else:
            self._generate_non_perfect()
