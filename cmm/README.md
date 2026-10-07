echo 'export UV_PROJECT_ENVIRONMENT=/var/tmp/luli2/cmm-venv' >> ~/.zshrc
echo 'export UV_CACHE_DIR=/var/tmp/luli2/uv-cache' >> ~/.zshrc
echo 'export HF_HOME=/var/tmp/luli2/huggingface' >> ~/.zshrc

source ~/.zshrc

mkdir -p /var/tmp/luli2/cmm-venv /var/tmp/luli2/uv-cache
export UV_PROJECT_ENVIRONMENT=/var/tmp/luli2/cmm-venv
export UV_CACHE_DIR=/var/tmp/luli2/uv-cache
uv sync

du -sh /var/tmp/luli2/cmm-venv
du -sh /var/tmp/luli2/uv-cache
du -sh /var/tmp/luli2/huggingface