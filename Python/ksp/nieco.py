file_path = "/home/martin/Desktop/Programy/Python/ksp/slepuch.txt"

with open(file_path, "r") as file:
    content = file.read()

converted_content = ""
for char in content:
    converted_content += str(ord(char)) + " "

print(converted_content)
