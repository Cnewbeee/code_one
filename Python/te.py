import requests
import json

def query_ollama(prompt, model="deepseek-r1", max_tokens=100):
    """
    调用 Ollama API 获取模型回答。
    :param prompt: 输入的提示文本
    :param model: 使用的模型，默认为 DeepSeek-R1
    :param max_tokens: 最大生成 token 数量
    :return: 模型生成的回答
    """
    url = "http://localhost:11434/api/generate"
    headers = {"Content-Type": "application/json"}
    data = {
        "model": model,
        "prompt": prompt,
        "max_tokens": max_tokens,
        "stream": False  # 设置为 False 以获取完整响应
    }

    response = requests.post(url, headers=headers, data=json.dumps(data))
    response.raise_for_status()  # 检查请求是否成功
    result = response.json()

    return result.get("response", "")

# 示例调用
prompt = "请直接给出答案，不要分析过程：从以下文本中提取甲方和乙方信息。\n合同甲方为：XX公司，乙方为：YY公司。"
answer = query_ollama(prompt, max_tokens=100)
print("直接答案：", answer)
