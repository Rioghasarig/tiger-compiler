import requests

for i in range(1, 50):
    file_name = f'test{i}.tig'
    url = f'https://www.cs.princeton.edu/~appel/modern/testcases/{file_name}'
    response = requests.get(url)
    with open(file_name, 'wb') as f:
        f.write(response.content)
    print(f'Downloaded {file_name}')

