*This project has been created as part of the 42 curriculum by luli2*




<!--
Describe：
在虚拟机环境下安装Debian系统，并进行minimal安装和分区、权限、服务器内部安全网（密码策略、Sudo 审计、UFW 防火墙、SSH 端口）配置、 writing msg script。


Instruction：
分区：
	Guided - use entire disk and set up encrypted LVM | Separate /home partition 自动创建 root (/)、swap 和 home (/home) 三个逻辑卷。


密码策略:
sudo nano /etc/pam.d/common-password
minlen=10：密码长度至少 10 位。
ucredit=-1, lcredit=-1, dcredit=-1：强制要求至少包含一个大写字母、一个小写字母和数字。
maxrepeat=3：禁止超过 3 个连续的相同字符（如 aaaa 是不允许的）。
difok=7：新密码必须与旧密码有至少 7 位不同。
gecoscheck=1：禁止密码包含你的用户名（防止被轻易猜到）。
enforce_for_root：root 用户改密码也要遵守这些规则。
requiretty TTY

sudo nano /etc/login.defs
PASS_MAX_DAYS   30
PASS_MIN_DAYS   2
PASS_WARN_AGE   7

sudo chage -m 2 -M 30 -W 7 luli2
sudo chage -l luli2


安全策略：
Sudo:
sudo mkdir -p /var/log/sudo | sudo visudo
sudo sudoreplay -l -d /var/log/sudo | sudo sudoreplay -d /var/log/sudo 000001
visudo 的保护机制：visudo 并不是一个普通的编辑器，它本质上是一个带锁的语法检查器 (Syntax checker)。


SSH：
sudo nano /etc/ssh/sshd_config | Port 4242 | PermitRootLogin no
sudo systemctl restart ssh | sudo systemctl status ssh
ss -tunlp
UFW:
sudo ufw default deny incoming | sudo ufw default allow outgoing | sudo ufw allow 4242
sudo ufw status


用户管理：
groups
sudo adduser <new_username>
groupadd user42
usermod -aG user42 luli2


已安装的服务：
	仅安装SSH+standard system utilities
	安装sudo, 配置用户组groupadd/usermod -aG
	libpam-pwquality插件：密码复杂度sudo nano /etc/pam.d/common-password retry=3：输入错误 3 次就断开连接。


定时：
sudo crontab -e
* * * * * 这五个星号分别代表：分钟、小时、日期、月份、星期几。
uname 命令从内核（Kernel）获取系统信息。参数 -a (all) 会返回内核版本、主机名、处理器架构和操作系统类型。
sort | uniq 去重（Eliminate duplicates），再用 wc -l 计数，得到物理硬件的数量。processor 条目代表逻辑核心（包含超线程）。直接计数即得到虚拟 CPU 总数。
free -m 从 /proc/meminfo 提取内存统计并以 MB 为单位显示。
df -Bg 以 GB 为单位列出文件系统。grep '^/dev/' 只看真实的物理磁盘分区；grep -v '/boot$' 排除（Exclude）掉启动分区
top -bn1 运行一次批处理模式（Batch mode）的性能检测.CPU 负载通常由用户态（us）和内核态（sy）相加得出
who -b (boot) 直接查询系统的启动时间戳
lsblk 列出块设备树。如果输出中包含 "lvm" 字符，说明逻辑卷管理（Logical Volume Management）已启用
sudo crontab -e #


bash:
sudo /usr/local/bin/monitoring.sh

test:
sudo su -
head -n 2 /etc/os-release
/usr/sbin/aa-status
ss -tunlp
/usr/sbin/ufw status

sudo adduser testuser
hostname -I
ssh testuser@ -p 4242
sudo deluser --remove-home testuser

sudo usermod -aG user42 evaluator
groups evaluator

passwd
sudo passwd root
 <host>
 sudo nano /etc/hostname
 sudo nano /etc/hosts
 sudo reboot


aptitude/apt:
	apt: simple, manul fix
	aptitude: offer choices
Debian与Rocky的比较：
	使用Debian，适合新手，极简稳定。Rocky更复杂的企业安全级标准。
AppArmor与SELInux的区别：
	aa: 限制可以活动的路径
	SE: base label
UFW与防火墙：
	UFW: 简化操作板
	防火墙: 内核中的网络过滤器
VirtualBox与UTM：
	vb: 虚拟机代码交给物理机执行，要求cpu架构一致
	utm: 如果是跨架构启用QEMU重编译

Eva:
`物理资源虚拟化，分割误以为独占。提供隔离环境。

sudo ufw status
sudo systemctl status ssh
hostnamectl

groups luli2
sudo adduser new
密码：sudo nano /etc/pam.d/common-password | sudo nano /etc/login.defs
sudo addgroup newg
sudo usermod -aG new newg

hostname
 <host>
 sudo nano /etc/hostname
 sudo nano /etc/hosts
 sudo reboot
lsblk
LVM: 把物理盘变成卷组（虚拟存储池），动态分配

‘dpkg -l | grep sudo’
sudo usermod -aG sudo xxx
SUDO: 权限管理并追踪
sudo visudo
sudo cat /var/log/sudo/sudo.log
`sudoreplay -l -d /var/log/sudo
sudoreplay -d /var/log/sudo xxxxxx

`sudo ufw status verbose
sudo ufw status numbered
sudo ufw allow 8080
sudo ufw delete xxx

SSH: 加密通道
·dpkg -l | grep openssh-server
`sudo systemctl status ssh
sudo ss -tunlp
sudo cat /etc/ssh/sshd_config
`ip a
ssh user@ip/localhost -p 4242
ssh root@~

cat /usr/local/bin/monitoring.sh

cron: 基于时间的调度器
sudo crontab -e

Resource：
AI：指导安装并解答
-->