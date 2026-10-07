from llm_sdk import Small_LLM_Model

model = Small_LLM_Model()

prompt = """
Available function:
fn_add_numbers(a: number, b: number)
Description: Add two numbers together.

User: What is the sum of 2 and 3?

Return the function name and parameters as JSON:
"""

input_ids = model.encode(prompt)[0].tolist()

for _ in range(40):
    logits = model.get_logits_from_input_ids(input_ids)
    next_token_id = logits.index(max(logits))
    input_ids.append(next_token_id)

#next_token = model.decode([next_token_id])

print(model.decode(input_ids))