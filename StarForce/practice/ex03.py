import re
import os, sys
import sympy as sy
from collections import OrderedDict

line="temp_117 = omni_virtualcode_121[ ( ( ( ( (unsigned int)122) + ( (unsigned int)19u)) + ( (unsigned int)4294967166u)) + ( (unsigned int)1u)) ];"
line2="temp_113 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( void ** )(temp_112)) + ( (size_t)1u)) + ( (size_t)1u)) + ( (size_t)1u)) + ( (size_t)1u)) + ( (size_t)1u)) + ( (size_t)1u)) + ( (size_t)1u)) + ( (size_t)1u)) + ( (size_t)1u)) + ( (size_t)1u)) + ( (size_t)1u)) + ( (size_t)1u)) + ( (size_t)1u)) + ( (size_t)1u)) + ( (size_t)1u)) + ( (size_t)1u);"
line3="temp_39 = ( bool )( ( (bool)0) == 0 );"
line4="temp_94 = &state1_29;"
line5="temp_117 = temp_117 ^ temp_118;"
line6="*temp_113 =  ( &temp_66);"
line6="temp_111 =  &temp_27;"
line7="temp_54 = ( int )( ( size_t )( temp_54 ) + ( ( ( size_t )( temp_54 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_54 ) << 31 ) << 1 ) >> 15 ) );"
line8="temp_122 = ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( (unsigned int)122) + ( (unsigned int)19u)) + ( (unsigned int)4294967166u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)5u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)100u)) + ( (unsigned int)4294967186u)) + ( (unsigned int)10u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)18u)) + ( ( unsigned int )( ( size_t )( ( ( ( (unsigned int)4294967278u) - ( ( ( unsigned int )(( ( bool )( ( ( bool )( ( ( bool )( ( (bool)( (bool)( ( bool )( ( (bool)0) == 0 )))) == 0 )) == 0 )) == 0 )))) * ( (unsigned int)4743u))) ) & 0xFFFFFFFF ) ))) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)89u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)1u)) + ( (unsigned int)7u)) + ( ( unsigned int )( ( size_t )( ( ( ( (unsigned int)4294967275u) - ( ( ( unsigned int )(( (bool)( ( bool )( ( (bool)( (bool)( ( bool )( ( (bool)0) == 0 )))) == 0 ))))) * ( (unsigned int)1793779649u))) ) & 0xFFFFFFFF ) ))) + ( ( unsigned int )( ( size_t )( ( ( ( (unsigned int)20u) - ( ( ( unsigned int )(( ( bool )( ( ( bool )( ( ( bool )( ( (bool)( (bool)( ( bool )( ( (bool)0) == 0 )))) == 0 )) == 0 )) == 0 )))) * ( (unsigned int)1u))) ) & 0xFFFFFFFF ) ))) + ( (unsigned int)4294967168u)) + ( (unsigned int)33u)) + ( (unsigned int)4294967268u)) + ( ( unsigned int )( ( size_t )( ( ( ( (unsigned int)72u) + ( ( ( unsigned int )(( ( bool )( ( ( bool )( ( ( bool )( ( ( bool )( ( (bool)( (bool)( ( bool )( ( (bool)0) == 0 )))) == 0 )) == 0 )) == 0 )) == 0 )))) * ( (unsigned int)7u))) ) & 0xFFFFFFFF ) ))) + ( ( unsigned int )( ( size_t )( ( ( ( (unsigned int)34u) + ( ( ( unsigned int )(( ( bool )( ( ( bool )( ( (bool)( (bool)( ( bool )( ( (bool)0) == 0 )))) == 0 )) == 0 )))) * ( (unsigned int)4u))) ) & 0xFFFFFFFF ) ));"
line9="temp_117 = temp_117 * ( ( unsigned int )(( *( ( bool * )(temp_119)))));"
line10="temp_37 = temp_37 + ( ( unsigned int )( ( size_t )( ( ( ( (unsigned int)3143u) - ( ( ( unsigned int )(( ( ( ( unsigned int )( temp_42 == 0 )) & temp_124) != ( (unsigned int)0u)))) * ( (unsigned int)2749u))) ) & 0xFFFFFFFF ) ));"
line11=" temp_84 = ( (unsigned int)12u) - ( ( ( unsigned int )(temp_45)) * ( (unsigned int)2u));"
line12="temp_122 =  ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ( ((unsigned int)(unsigned int) 122) + ((unsigned int)(unsigned int) 19)) + ((unsigned int) 4294967166)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 5)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int)(unsigned int)(unsigned int) 100)) + ((unsigned int) 4294967186)) + ((unsigned int)(unsigned int) 10)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int)(unsigned int) 18)) + ( ( ( ( ( ((unsigned int) 4294967278) - ( ( (temp_44)) * ((unsigned int) 4743))) ) &(unsigned int) 0xFFFFFFFF ) ))) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 89)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 1)) + ((unsigned int) 7)) + ( ( ( ( ( ((unsigned int) 4294967275) - ( ( (temp_40)) * ((unsigned int)(unsigned int) 1793779649))) ) &(unsigned int) 0xFFFFFFFF ) ))) + ( ( ( ( ( ((unsigned int) 20) - ( ( (temp_44)) * ((unsigned int) 1))) ) &(unsigned int) 0xFFFFFFFF ) ))) + ((unsigned int) 4294967168)) + ((unsigned int) 33);"
line13="temp_37 = temp_37 + ( ( unsigned int )( ( size_t )( ( ( ( (unsigned int)3143u) - ( ( ( unsigned int )(( ( ( ( unsigned int )( temp_42 == 0 )) & temp_124) != ( (unsigned int)0u)))) * ( (unsigned int)2749u))) ) & 0xFFFFFFFF ) ));"
line14="temp_135 = &argv_1;"
line15="temp_54 = (int)2062554531u;"
line16="unsigned int crc=~0;"
line17=" temp_149 = ( unsigned int )( ( size_t )( temp_149 ) + ( ( ( size_t )( temp_149 ) << 31 ) << 1 ) + ( ( ( ( size_t )( temp_149 ) << 31 ) << 1 ) >> 15 ) );"
line18="temp_149 = ( unsigned int ) ( ( size_t )( temp_149 ) + ( ( ( size_t )( temp_149 ) <<(unsigned int) 31 ) <<(unsigned int) 1 ) + ( ( ( ( size_t )( temp_149 ) <<(unsigned int) 31 ) <<(unsigned int) 1 ) >>(unsigned int) 15 ) );"
line19="temp_98 = ( (unsigned int)4294967292u) - ( ( ( unsigned int )(( (bool)temp_53))) * ( (unsigned int)6u));"
line20="temp_84 = ( (unsigned int)417293886u) - ( ( ( unsigned int )(( ( bool )( ( (bool)0) == 0 )))) * ( (unsigned int)417293888u));"
line21="temp_117 = omni_virtualcode_121[ ( ( ( (unsigned int)122) + ( (unsigned int)19u)) + ( (unsigned int)4294967166u)) ];"
line22=" temp_98 = ( (unsigned int)242u) + ( ( ( unsigned int )(temp_53)) * ( (unsigned int)4u));"
line23="temp_1=4*temp_2+4;"
line24="temp_150 = ( bool )( ( *temp_153) == 0 );"
#arg_num3=re.findall(r"",line)
#a=line.split()
#print(a)

exclude_list=["unsigned int", "bool"]
alternate_variable=[r"\(\s*void\s?\*\*\s*\)\(\s*[*&]?temp_\d+\s*\)",r"\(\s*size_t\s*\)\(\s*[*&]?temp_\d+\s*\)",r"\(?\s*[*&]?state\d+_\d+\s*\)?",r"\(?\s*[*&]?temp_\d+\s*\)?",r"\(?\s*[*&]?omni_virtualcode_\d+\s*\)?", r"\(?\s*[*&]?state\d+_\d+\s*\)?", r"\s*&argv_\d+\s*"]
def exclude(line, ex_list=exclude_list):
	for pattern in ex_list:
		line=re.sub(pattern='\(\s*'+pattern+'\s*\)', repl=' ', string=line)
	return line
def simple(line):
	dic=OrderedDict()
	temp=[]
	front=''
	back=''
	unsigned_int_flag=False
	if re.match(r"\s*temp_\d+\s*=\s*\(\s*unsigned int\s*\)", line):
		unsigned_int_flag=True
	print(unsigned_int_flag)
	if re.search(r"[^=><]=", line) and re.search(r";", line) and not re.search(r"char", line) and not re.search(r"\^", line):
		front=re.search(r"([^=]*)={1}[\s\S]*;\s*",line).group(1)
		line=re.search(r"([^=]*)={1}([\s\S]*;)\s*",line).group(2)
		
	else:
		return line
	
	if line.find(";")!=-1:
		back=";"+line.split(";")[1]
		line=line.split(";")[0]
	print(line)
	line=exclude(line)
	print(line+"\n")
	for variable in alternate_variable:
		temp+=re.findall(variable, line)
	print(temp)
	print("\n")
	for i in range(len(temp)):
		dic[temp[i]]=chr(71+i)
	for i in dic:
		line=line.replace(i, dic[i])
	for i in re.findall(r"\d+u", line):
	  line=re.sub(pattern=i, repl=i[:-1],string=line)
	print(line+"\n")
	line=exclude(line, ex_list=["size_t"])
	print(line)
	if re.match(r"\s*\(?\s*[A-Z]\s*==\s*0\s*\)?\s*",line):
		for i in dic:
			line=line.replace(dic[i],i)
		if unsigned_int_flag:
			line="( unsigned int )"+line
		line=front+"= "+line
		return line+back+"\n"

	try:
		line=line.replace(re.search(r"\[[\S\s]*\]",line).group(0),str(eval(re.search(r"\[[\S\s]*\]",line).group(0))))
	except:
		try:
			line=str(sy.simplify(line))
			#line=str(eval(line))
		except:	
			
			line=str(eval(line))
			
			#print("@@"+line+"\n\n")
	
	finally:
		#print("&&"+line+"\n")
		print(line+"\n")
		temp=set(re.findall(r"[-]?\s*\d+\s*", line))
		
		print(temp)
		print("\n")
		print(line)
		for i in temp:
			if "-" in i:
				print(i.split("-"))
				line=re.sub(i, i.split("-")[0]+"-(unsigned int) "+i.split("-")[1],line)
			else:
				print("YAH")
				line=re.sub(i, "(unsigned int)"+i.strip(),line)
			print(line)
		for i in dic:
			line=line.replace(dic[i],i)
		if unsigned_int_flag:
			line="( unsigned int )"+line
		line=front+"= "+line
		return line+back+"\n"
"""
SourceCode = open(sys.argv[1], 'r', encoding="utf-8")
NewSourceCode= open("new.c", 'w')
ErrorCode=open("error.txt",'w')
while True:
	Readline=SourceCode.readline()
	try:
		Readline=simple(Readline)
		Readline=Readline.replace("True","true")
		Readline=Readline.replace("False","false")
		NewSourceCode.write(Readline)
	except:
		ErrorCode.write(Readline)
	if not Readline:
		break
SourceCode.close()
NewSourceCode.close()
ErrorCode.close()
"""
#print(simple(line))
#print(simple(line2))
#print(simple(line3))
#print(simple(line4))
#print(simple(line5))
#print(simple(line6))
#print(simple(line7))
#print(simple(line8))
#print(simple(line9))
#print(simple(line10))
#print(simple(line11))
#print(simple(line12))
#print(simple(line13))
#print(simple(line14))
#print(simple(line15))
print(simple(line24))