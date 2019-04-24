import re
 
text = "문의사항이 있으면 032-232-3245 으로 연락주시기 바랍니다."
 
regex = re.compile(r'\d\d\d-\d\d\d-\d\d\d\d')
matchobj = regex.search(text)
phonenumber = matchobj.group()
print(type(phonenumber))
print(phonenumber)    

text2 = "에러 1122 : 레퍼런스 오류\n 에러 1033: 아규먼트 오류"
regex = re.compile("에러\s\d+")
mc = regex.findall(text2)
print(mc)

ReadLine="// Obfuscator generated function\n"
ExtractFunction1=re.search(r'// Obfuscator generated function', ReadLine) # Extract Function 1
print(ExtractFunction1.group())

p=re.compile('\W*abc')
m=p.search('    abcd')
print(m.group()+"pp")
