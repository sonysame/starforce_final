import re
from collections import defaultdict

f=open("result2.txt",'w')
s=['a','b','c','b','a','b','c']
s2=[('yellow', 1), ('blue', 2), ('yellow', 3), ('blue', 4), ('red', 1)]

dic1={}
dic2={}

for i in s:
	if i not in dic1.keys():
		dic1[i]=0
	dic1[i]+=1
print(dic1)

for i in s:
	dic2.setdefault(i,0) #setdefault gets key and its default value
	dic2[i]+=1
print(dic2)

#defaultdict is faster than setdefault
dic3=defaultdict(int)
for i in s:
	dic3[i]+=1
print(dict(dic3))

dic4=defaultdict(lambda:["",True])
dic4[0]=["GOOD",True]
dic4[3]=["Hello",False]
print(dic4)
for i,v in dic4.items():
	print(i,v)

f.close()
ReadLine="temp_126 = ( int * )(temp_119);"
ReadLine2="temp_118 = omni_virtualcode_121[ temp_124 ];"
ReadLine3="temp_123 = temp_123 + temp_117;"
a= re.match(r'\s*(\S*temp_\d+)\s{1}=\s{1}[\d\s\w\S]*(\S*temp_\d+)[\s\S]*0xFFFFFFFF',ReadLine) # Example :: "temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF;"
b= re.match(r'\s*(\S*temp_\d+)\s{1}=\s{1}[\d\s\w\S]*(\S*temp_\d+)[\d\s\w\S]*(\S*temp_\d+)[\d\s\w\S]*(\S*temp_\d+)',ReadLine) # Example :: X            
c= re.match(r"\s*(\S*temp_\d+)\s{1}=\s{1}\W*\s?\D*\W*(\d+)u;", ReadLine) # Example :: "temp_85 = (unsigned int)1351u;"
d= re.match(r"\s*(\S*temp_\d+)\s{1}=\s{1}(\S*temp_\d+);", ReadLine) # Example :: "*temp_77 = temp_37;"
e= re.match(r"\s*(\S*temp_\d+)\s{1}=\s{1}[\s\w\D]*(temp_\d+)\b(?!temp_\b)*;", ReadLine) # Example :: "temp_77 = ( unsigned int * )(temp_57);"

f= re.match(r"\s*(\S*temp_\d+)\s{1}=\s{1}(\S*temp_\d+)\s?\S+\s?(\S*temp_\d+)\s?\S?;", ReadLine) # Example :: "temp_84 = temp_84 * temp_85;"
print(a,b,c,d,e,f)
#re.search(r"\[[\S\s]*\]",re.findall(r"=([\W\w]*);",LeftHandSideList[sub_target][0])[0]):
arg_num=re.search(r"\[.*\]",re.findall(r"=([\W\w]*);",ReadLine)[0])
arg_num2=re.findall(r"(temp_\d*)",ReadLine2)
arg_num3=re.findall(r"(temp_\d*)",ReadLine3)
print(arg_num3)
if(arg_num is None):
	print("HEEYEON")
print(re.findall(r"=([\W\w]*);",ReadLine)[0]+"NUM IS "+str(arg_num))
print("NUM IS "+str(arg_num2))
print("NUM IS "+str(arg_num3)+arg_num3[0])
k=re.findall(r"=([\W\w]*);",ReadLine3)
print(k[0])

dic4["hi"]=["HEEYEIN",True]
del dic4["hi"]
if "hi" in dic4:
	print(dic4["hi"])
else:
	print("YEAH")

some_list = ['abc-123', 'def-456', 'ghi-789', 'abc-456']

#길게 쓰면
for s in some_list:
    if "abc" in s:
        print("있다")
        break; #하나만 찾으면 뒤는 안 찾음

print(dic4)
dic4=defaultdict(lambda:["",True])
print(dic4)