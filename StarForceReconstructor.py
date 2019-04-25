import sys, os, re, operator
from collections import defaultdict
import sympy as sy
from collections import OrderedDict

# Label & Dispatcher
#LabelDict = defaultdict(lambda: "") # Label Box Dictionary
LabelCounter = defaultdict(lambda: 0) # Dispatcher Identification
LabelList = []

# Variable
LeftHandSideList = defaultdict(lambda: ["",True]) # Writing the Arguments of Left-Hand Side
ReadLine=""

#Propagation
PropagationFlag = False

# Optimization Value
OptimizingStatement = ''
OptimizedFlag = False

FunctionFlag1 = False
FunctionFlag2 = False

OptimizedLineCounter = 0 # Writing the Number of Line Deleted by Our Optimization
PropagtionOptimizedCounter = 0

used_function=["printf"]
exclude_list=["unsigned int", "bool"]
alternate_variable=[r"\(\s*void\s?\*\*\s*\)\(\s*[*&]?temp_\d+\s*\)",r"\(\s*size_t\s*\)\(\s*[*&]?temp_\d+\s*\)",r"\(?\s*[*&]?state\d+_\d+\s*\)?",r"\(?\s*[*&]?temp_\d+\s*\)?",r"\(?\s*[*&]?omni_virtualcode_\d+\s*\)?", r"\s*&argv_\d+\s*", r"\s*&argc_\d+\s*", r"\s*&test_\d+\s*"]

OnlyControlFlow=False


def exclude(line, ex_list=exclude_list):
   for pattern in ex_list:
      line=re.sub(pattern='\(\s*'+pattern+'\s*\)', repl='', string=line)
   return line

def simple(line):
   dic=OrderedDict()
   temp=[]
   front=''
   back=''
  
   unsigned_int_flag=False
   if re.match(r"\s*temp_\d+\s*=\s*\(\s*unsigned int\s*\)\s*\(", line):
      unsigned_int_flag=True

   if re.search(r"[^=><]=", line) and re.search(r";", line) and not re.search(r"char", line) and not re.search(r"\^", line):
      front=re.search(r"([^=]*)={1}[\s\S]*;\s*",line).group(1)
      line=re.search(r"([^=]*)={1}([\s\S]*;)\s*",line).group(2)
      
   else:
      return line
   
   if line.find(";")!=-1:
      back=";"+line.split(";")[1]
      line=line.split(";")[0]
   line=exclude(line)

   for variable in alternate_variable:
      temp+=re.findall(variable, line)
   for i in range(len(temp)):
      dic[temp[i]]=chr(71+i)
   for i in dic:
      line=line.replace(i, dic[i])
   for i in re.findall(r"\d+u", line):
     line=re.sub(pattern=i, repl=i[:-1],string=line)
   
   line=exclude(line, ex_list=["size_t"])

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
      except:  
         line=str(eval(line))
      
   finally:
      temp=set(re.findall(r"\s*[-]?\d+\s*", line))
      for i in temp:
         if "-" in i:
            line=re.sub(i, i.split("-")[0]+"-(unsigned int) "+i.split("-")[1],line,1)
         else:
            line=re.sub(i, "(unsigned int) "+i,line,1)
      for i in dic:
         line=line.replace(dic[i],i)

      if unsigned_int_flag:
         line="( unsigned int )"+line
      
      line=front+"= "+line
      
      return line+back+"\n"

def find_function(str):
   global used_function

   for i in used_function:
      if i in str:
         return False
   return True

def UpdateOptimization(arg):
   global OptimizedFlag
   global OptimizingStatement
   global LeftHandSideList

   if not arg[0] in LeftHandSideList:
      if arg[0] in ExceptList:
         LeftHandSideList[arg[0]]=[ReadLine,False]
      else:
         LeftHandSideList[arg[0]]=[ReadLine,True]
   else:
      if(LeftHandSideList[arg[0]][1]) and arg[0].find("*")==-1:
         OptimizingStatement = LeftHandSideList[arg[0]][0]
         OptimizedFlag = True

      if arg[0] in ExceptList:
         LeftHandSideList[arg[0]]= [ReadLine,False]
      else:
         LeftHandSideList[arg[0]]= [ReadLine,True]


def RemoveListDel(arg):
   global LeftHandSideList
   RemoveList=[]

   for i in LeftHandSideList:
      temp_arg=re.findall(r"([*&]?temp_\d*)",LeftHandSideList[i][0])
      for j in range(1, len(temp_arg)):
         if temp_arg[j]==arg[0]:
            RemoveList.append(i)
   for i in RemoveList:
      if i in LeftHandSideList:
         del LeftHandSideList[i]

def Propagation(arg, index):
   global LeftHandSideList
   global PropagationFlag
   global ReadLine

   MakeFalseFlag=True
   sub_target=arg[index]
   if sub_target.find("*") != -1:
      sub_target=sub_target.split("*")[-1]

   if sub_target in LeftHandSideList:
      if re.search(r"\[.*\]",re.findall(r"=([\W\w]*);",LeftHandSideList[sub_target][0])[0]) is None and find_function(re.findall(r"=([\W\w]*);",LeftHandSideList[sub_target][0])[0]):
         FunctionExcludeFlag=False
         for i in FunctionList:
            if i in LeftHandSideList[sub_target][0]:
               FunctionExcludeFlag=True
               break
         if "bool" not in LeftHandSideList[sub_target][0] and FunctionExcludeFlag is False:
            if arg[0] != sub_target:
               PropagationFlag = True
               ReadLine = re.sub(re.escape(sub_target), '('+re.findall(r"=([\W\w]*);",LeftHandSideList[sub_target][0])[0]+')', ReadLine)
               MakeFalseFlag=False
            else:
               PropagationFlag = True
               ReadLine = re.sub("\S\s*"+re.escape(sub_target), re.search(r'(\S\s*)'+re.escape(sub_target), ReadLine).group(1)+'('+re.findall(r"=([\W\w]*);",LeftHandSideList[sub_target][0])[0]+')', ReadLine, 1)
               MakeFalseFlag=False 

      if MakeFalseFlag==True:
         if arg[index] in LeftHandSideList:
            LeftHandSideList[arg[index]][1]=False

def AddressDel(arg, index):
   global LeftHandSideList
   if arg[index].find("&")!=-1 and arg[index].split("&")[-1] in LeftHandSideList:
      del LeftHandSideList[arg[index].split("&")[-1]]

def StmtAnalysis(arg):
   global OptimizedFlag
   global OptimizingStatement
   global LeftHandSideList
   global PropagtionOptimizedCounter
   global PropagationFlag
   global ReadLine
 
   ArgNum=len(arg)

   if ArgNum == 1:
      UpdateOptimization(arg)
      RemoveListDel(arg)

   if ArgNum == 2:
      if(re.match(r"\s*\*temp_\d+\s*=\s*\(?\s*&temp_\d+\s*\)?\s*;\s*",ReadLine)):
         if arg[1].split("&")[-1] not in ExceptList:
            ExceptList.append(arg[1].split("&")[-1])
      
      if arg[0].find("*")!=-1:
         if arg[0].split("*")[-1] in LeftHandSideList:
             LeftHandSideList[arg[0].split("*")[-1]][1]=False

      Propagation(arg, 1)
      AddressDel(arg,1)
      UpdateOptimization(arg)
      RemoveListDel(arg)
               
   if ArgNum == 3:
      if arg[0].find("*")!=-1:
         if arg[0].split("*")[-1] in LeftHandSideList:
            LeftHandSideList[arg[0].split("*")[-1]][1]=False
      
      Propagation(arg,1)
      Propagation(arg,2)
      AddressDel(arg,1)
      AddressDel(arg,2)
      UpdateOptimization(arg)
      RemoveListDel(arg)
      
   if ArgNum == 4:
      if arg[0] in LeftHandSideList:
         del LeftHandSideList[arg[0]]
      AddressDel(arg,1)
      AddressDel(arg,2)
      AddressDel(arg,3)
      
def Compile(SourceCodeName, SourceCode):
   # GCC is Needed 
   Compile = "gcc " + SourceCodeName + "." + SourceCode.split(".")[1] + " -o " + SourceCodeName + " -w"
  # Compile2 = "clang " + 
   os.system(Compile)

def Clear(SourceCodeName):
   ch=input("Do you want to remove all the previous files? (Y/N) ")
   if(ch=='Y' or ch=='y'):
      Clear = "rm " + SourceCodeName.split(".")[0] + "_*"
      os.system(Clear)
def Execute(ProgramName, Log):
   Execute = "./" + ProgramName
   if Log:
      Execute += " > " + ProgramName + "[Log].txt"
   os.system(Execute)

def get_function_name():
   os.system("python func_name_extract.py "+sys.argv[1]+" result.txt")
   FunctionName=open("result.txt",'r')
   while True:
      function=FunctionName.readline()
      if not function: 
         break
      if function.find("\n")!=-1:
         function=function.split("\n")[0]
      if function !='main':
         FunctionList.append(function)

   FunctionName.close()

def Optimization(SourceCode):

   global ReadLine
   global OptimizedFlag
   global OptimizingStatement
   global LeftHandSideList
   global PropagationFlag

   global OptimizedLineCounter
   global PropagtionOptimizedCounter
   global FunctionFlag1
   global FunctionFlag2
   
   
   SettingFlag = False
   
   RecordFlag = False
   RecordIndex = 0 # Writing the Number of Labels written now
   
   OptimizedLineCounter = 0 # Writing the Number of Line Deleted by Our Optimization
   PropagtionOptimizedCounter = 0

   OptimizedCodeName =sys.argv[1].split(".")[0] + "_[OptimizedCode]["+str(Round) + "Round]"
   OptimizedSourceCode = open(OptimizedCodeName + "." + sys.argv[1].split(".")[1], 'w')

   UsedLabel = []
   TotalLabel=[]

   LabelDict = defaultdict(lambda: "")

   if(Round==1):   
      LabelAppendedCodeName = sys.argv[1].split(".")[0] + "_[LabelAppendedCode]"
      LabelAppendedCodeSourceCode = open(LabelAppendedCodeName + "." + sys.argv[1].split(".")[1], 'w')
      
   
   
   while True:
      # Source Code Rewriting

      ReadLine = ObfuscatedSourceCode.readline()
      if not ReadLine: break
      
      if(Round==1):
         LabelAppendedCodeSourceCode.write(ReadLine)

      # Regular Expression
      
      # Extract Function
      ExtractFunction1 = re.match(r'\/\/ Obfuscator generated function', ReadLine) # Extract Function 1
      ExtractFunction2 = re.match(r'static void omni_global_function', ReadLine) # Extract Function 2

      # Extract Label & Dispatcher
      ExtractLabel = re.match(r'\s*(L\d+):', ReadLine) # Example :: "L100:"
      ExtractSwitch = re.match(r'\s*switch\(\s*\w*\)', ReadLine) # Example :: "switch(temp_36)"

      # Extract Goto & Return (Throw)
      ExtractGoto = re.match(r'\s*goto\s*L(\d+);', ReadLine) # Example :: "goto L100;"
      ExtractReturn = re.match(r'\s*return\s*;', ReadLine) # Example :: "return;"
      ExtractThrow = re.match(r'\s*throw\s*;', ReadLine) # Example :: "throw;"
      
      # Extract Statement
      arg=re.findall(r"([*&]?temp_\d*)",ReadLine)
      if '=' not in ReadLine:
         arg=[]

      if ExtractFunction1: # Extract Pattern :: // Obfuscator generated function
         FunctionFlag1 = True

      if ExtractFunction2 and FunctionFlag1: # Extract Pattern :: static void omni_global_function
         FunctionFlag2 = True

      if FunctionFlag2:
         if(Round==1):
            if ExtractLabel:
               RecordFlag = True
               SettingFlag = True # Label Extracted :: Insert Label Box
               LabelAppendedCodeSourceCode.write(" "*(len(ReadLine)-len(ExtractLabel.group(1))-2) + "printf(\"" + ExtractLabel.group(1) + "\\n" + "\");" + "\n")
               RecordIndex = ExtractLabel.group(1)[1:] # Label Number Extraction
               LabelList.append(RecordIndex) # Label Number Append
         else:
            RecordFlag = True
            SettingFlag = True # Label Extracted :: Insert Label Box
            RecordIndex = 0
            LabelList.append(RecordIndex) # Label Number Append
         
         if not OnlyControlFlow:
            StmtAnalysis(arg)

         if SettingFlag:
            LabelDict[RecordIndex] += ReadLine
            if OptimizedFlag:
               LabelDict[RecordIndex] = ''.join(LabelDict[RecordIndex].rsplit(OptimizingStatement, 1))
               OptimizedLineCounter += 1
               OptimizedFlag = False

            if PropagationFlag:
               PropagtionOptimizedCounter += 1
               PropagationFlag = False
               
               
         if ExtractGoto or ExtractReturn or ExtractThrow:
            LeftHandSideList = defaultdict(lambda: ["",True])
            SettingFlag = False

      if not RecordFlag:
         OptimizedSourceCode.write(ReadLine)


   if(Round==1):
      LabelAppendedCodeSourceCode.close()
      Compile(LabelAppendedCodeName, SourceCode)
      Execute(LabelAppendedCodeName, True)
      try:
         LogFile = open(LabelAppendedCodeName + "[Log].txt", 'r')
      except:
         print("Invalid Input Log File!")

      while True:
         LogReadLine = LogFile.readline()
         if not LogReadLine: break
         CheckLabel = re.match('\w*L(\d+)', LogReadLine)
         if(CheckLabel):
            TotalLabel.append(CheckLabel.group(1))
            if not CheckLabel.group(1) in UsedLabel:
               UsedLabel.append(CheckLabel.group(1))
            LabelCounter[CheckLabel.group(1)] += 1

      try:
         DispatcherLabel = max(LabelCounter, key=LabelCounter.get)
      except:
         DispatcherLabel=-1
      Dispatcher = False
      for index, i in enumerate(TotalLabel):
         LabelDict[i] = re.sub("\s*goto\s{1}L\d+;", '',LabelDict[i])
         LabelDict[i] = re.sub("\s*L\d+:", '', LabelDict[i])
         if i == DispatcherLabel:
            if not Dispatcher:
               Dispatcher = True
               OptimizedSourceCode.write("\t}\n")
               print("\n### Dispatcher Deletion & Code Block Reconstruction Complete ###\n")
               continue
            else:
               continue

         OptimizedSourceCode.write(LabelDict[i])

      OptimizedSourceCode.write("}")
      OptimizedSourceCode.close()

      
   
   else:
      OptimizedSourceCode.write(LabelDict[0])
      OptimizedSourceCode.close()

   
   print("### DeadCode Elimination Round", Round, ":", OptimizedLineCounter, "Line Optimized ###")
   print("### Constant Propagation Round", Round, ":", PropagtionOptimizedCounter, "Line Optimized ###")
   
   print("\n### Obfuscated Source Code Rewriting Complete ###")
   print("### Execution Result of Optimized Program ###\n")
   Compile(OptimizedCodeName, SourceCode)
   Execute(OptimizedCodeName, False)
   ObfuscatedSourceCode.close()      

   return (OptimizedCodeName)
  


if __name__=="__main__":


   if len(sys.argv) != 2 and len(sys.argv)!=3:
      print("Usage:: python StarForceReconstructor.py [InputSourceCode]")
      print("Example:: python StarForceReconstructor.py HelloWorld.c")
      exit()
   
   if(len(sys.argv)==3 and sys.argv[2]=="-c"):
      OnlyControlFlow=True

   code=sys.argv[1]
   FunctionList=[]
   get_function_name()
   #print(FunctionList)
   try: 
      Clear(code)
   except:
      pass
   Round=1
   Error=open("error.txt",'w', encoding="utf-8")
   while 1:
      
      try:
         print("\n\n"+str(Round)+"Round : "+code)
         ObfuscatedSourceCode = open(code, 'r', encoding="utf-8")
         print("Line Number is : {}".format(sum(1 for line in ObfuscatedSourceCode)))
         ObfuscatedSourceCode.close()
         ObfuscatedSourceCode = open(code, 'r', encoding="utf-8")

      except:
         print("Invalid Input Source Code!")
         exit()
      ExceptList=[]
      code=Optimization(code)+".c"
    
      if((OptimizedLineCounter+PropagtionOptimizedCounter)==0):
         print("\n===================DONE===================\n")
         break
      ObfuscatedSourceCode.close()   

      #exit()
      Round+=1
   if OnlyControlFlow:
      FinalCode = open(code, 'r', encoding="utf-8")
      print("Line Number is : {}".format(sum(1 for line in FinalCode)))
      FinalCode.close()
   else:
      SourceCode = open(code, 'r', encoding="utf-8")
      FinalCodeName=sys.argv[1].split(".")[0]+"_Final.c"
      FinalCode=open(FinalCodeName,'w')
      FinalCodeContents=""

      FunctionFlag1 = False
      FunctionFlag2 = False

      ExceptList=[]
      while True:
         ReadLine=SourceCode.readline()
         if not ReadLine:
            break
         
         ExtractFunction1 = re.match(r'\/\/ Obfuscator generated function', ReadLine) # Extract Function 1
         ExtractFunction2 = re.match(r'static void omni_global_function', ReadLine) # Extract Function 2
         if ExtractFunction1: # Extract Pattern :: // Obfuscator generated function
            FunctionFlag1 = True
         if ExtractFunction2 and FunctionFlag1: # Extract Pattern :: static void omni_global_function
            FunctionFlag2 = True
         if(FunctionFlag2):
            ReadLine=simple(ReadLine)
            ReadLine=ReadLine.replace("True","true")
            ReadLine=ReadLine.replace("False","false")
         
         FinalCodeContents+=ReadLine
         
      FinalCodeContents=FinalCodeContents.replace("\n\n","\n")

      #print(LeftHandSideList)
      FinalCode.write(FinalCodeContents)
      SourceCode.close()
      FinalCode.close()

      print("Final Source Code is : "+FinalCodeName)
      FinalSourceCode = open(FinalCodeName, 'r', encoding="utf-8")
      print("Line Number is : {}".format(sum(1 for line in FinalSourceCode)))
      FinalSourceCode.close()
      Compile(FinalCodeName.split(".")[0], FinalCodeName)
      Execute(FinalCodeName.split(".")[0], False)

      Error.close()