import sys, os, re, operator
from collections import defaultdict

if len(sys.argv) != 2:
   print("Usage:: python StarForceReconstructor.py [InputSourceCode]")
   print("Example:: python StarForceReconstructor.py HelloWorld.c")
   exit()


# Function
SettingFlag = False
FunctionFlag1 = False
FunctionFlag2 = False
RecordFlag = False
ReadLineNumber = 0
ReadLine = 0

# Label & Dispatcher
LabelDict = defaultdict(lambda: "") # Label Box Dictionary
LabelCounter = defaultdict(lambda: 0) # Dispatcher Identification
LabelList = []
RecordIndex = 0 # Writing the Number of Labels written now

# Variable
LeftHandSideList = defaultdict(lambda: "") # Writing the Arguments of Left-Hand Side
RightHandSideList = defaultdict(lambda: "") # Writing the Arguments of Right-Hand Side
StmtDict = defaultdict(lambda: "")

# Constant Optimization
ConstantVariableDict = defaultdict(lambda: "")
ConstantVariable = ''
#VariableDict=defaultdict(lambda: 0)
#VariableStatementDict=defaultdict(lambda: "")
ConstantPropagationFlag = False
ConstantOptimizationCounter = 0
ConstantStatement = ''

# Optimization Value
OptimizingStatement = ''
OptimizingConstant = ''
OptimizedFlag = False
OptimizedLineCounter = 0 # Writing the Number of Line Deleted by Our Optimization
OptimizationRound = 1

# New File Name
LabelAppendedCodeName = sys.argv[1].split(".")[0] + "_[LabelAppendedCode]"
OptimizedCodeName = sys.argv[1].split(".")[0] + "_[OptimizedCode][" + str(OptimizationRound) + "Round]"

# OptimizedCode Source Code (LabelAppendedCode & Optimized)
LabelAppendedCodeSourceCode = open(LabelAppendedCodeName + "." + sys.argv[1].split(".")[1], 'w')
OptimizedSourceCode = open(OptimizedCodeName + "." + sys.argv[1].split(".")[1], 'w')
#TestSourceCode = open("TestSourceCode." + sys.argv[1].split(".")[1], 'w')

CheckFlag=0

def StmtAnalysis(Stmt, ArgNum):
   global OptimizedFlag
   global OptimizingStatement
   global LeftHandSideList
   global ConstantVariableDict
   global ConstantVariable
   global ConstantOptimizationCounter
   global ConstantPropagationFlag
   global ConstantStatement
   global ReadLine
   global RecordIndex
   global OptimizationRound

   if ArgNum == 1:
      ConstantVariableDict = {Stmt.group(1):Stmt.group(2)}
      ConstantStatement = Stmt.group(0)
      ConstantVariable = Stmt.group(1)
      #VariableDict[Stmt.group(1)]=int(Stmt.group(2))


   if ArgNum == 3:
      if Stmt.group(2) in LeftHandSideList:
         del LeftHandSideList[Stmt.group(2)]
         try:
            del LeftHandSideList["*" + Stmt.group(2)]
         except:
            pass
      else:
         if Stmt.group(2).find("*") != -1:
            del LeftHandSideList[Stmt.group(2).split("*")[-1]]

         if Stmt.group(2).find("&") != -1:
            del LeftHandSideList[Stmt.group(2).split("&")[-1]]
      if Stmt.group(2) in ConstantVariableDict:
         if Stmt.group(1) != Stmt.group(2):   
            ConstantPropagationFlag = True
            ReadLine = re.sub(re.escape(Stmt.group(2)), ConstantVariableDict[Stmt.group(2)], Stmt.group(0), 1) + "\n"
         
         else:
            ConstantPropagationFlag = True
            #ReadLine = re.sub(re.escape(Stmt.group(2)), ConstantVariableDict[Stmt.group(2)], Stmt.group(0), 1) + "\n"
            ReadLine = re.sub("\S\s*"+re.escape(Stmt.group(2)), re.search(r'(\S\s*)'+re.escape(Stmt.group(2)), Stmt.group(0)).group(1)+ConstantVariableDict[Stmt.group(2)], Stmt.group(0), 1) + "\n"
            print(ConstantVariableDict, RecordIndex, Stmt.group(0)+"->"+ReadLine)

      if Stmt.group(3) in LeftHandSideList:
         del LeftHandSideList[Stmt.group(3)]
         try:
            del LeftHandSideList["*"+Stmt.group(3)]
         except:
            pass
      else:
         if Stmt.group(3).find("*") != -1:
            del LeftHandSideList[Stmt.group(3).split("*")[-1]]

         if Stmt.group(3).find("&") != -1:
            del LeftHandSideList[Stmt.group(3).split("&")[-1]]
      if Stmt.group(3) in ConstantVariableDict:
         if Stmt.group(1) != Stmt.group(3):
            ConstantPropagationFlag = True
            ReadLine = re.sub(re.escape(Stmt.group(3)), ConstantVariableDict[Stmt.group(3)], Stmt.group(0), 1) + "\n"
         else:
            ConstantPropagationFlag = True
            #ReadLine = re.sub(re.escape(Stmt.group(3)), ConstantVariableDict[Stmt.group(3)], Stmt.group(0), 1) + "\n"
            ReadLine = re.sub("\S\s*"+re.escape(Stmt.group(3)), re.search(r'(\S\s*)'+re.escape(Stmt.group(3)), Stmt.group(0)).group(1)+ConstantVariableDict[Stmt.group(3)], Stmt.group(0), 1) + "\n"
            print(Stmt.group(0)+"   ->"+ReadLine)

   if ArgNum == 2:
      if Stmt.group(2) in LeftHandSideList:
         del LeftHandSideList[Stmt.group(2)]
      else:
         if Stmt.group(2).find("*") != -1:
            del LeftHandSideList[Stmt.group(2).split("*")[-1]]
         if Stmt.group(2).find("&") != -1:
            try:
               del LeftHandSideList[Stmt.group(2).split("&")[-1]]
            except:
               pass
      if Stmt.group(2) in ConstantVariableDict:
         if Stmt.group(1) != Stmt.group(2):
            ConstantPropagationFlag = True
            ReadLine = re.sub(re.escape(Stmt.group(2)), ConstantVariableDict[Stmt.group(2)], Stmt.group(0), 1) + "\n"
         else:
            ConstantPropagationFlag = True
            #ReadLine = re.sub(re.escape(Stmt.group(2)), ConstantVariableDict[Stmt.group(2)], Stmt.group(0), 1) + "\n"
            ReadLine = re.sub("\S\s*"+re.escape(Stmt.group(2)), re.search(r'(\S\s*)'+re.escape(Stmt.group(2)), Stmt.group(0)).group(1)+ConstantVariableDict[Stmt.group(2)], Stmt.group(0), 1) + "\n"
            print(Stmt.group(0)+"->"+ReadLine)
   if ArgNum == -2:
      if Stmt.group(2) in LeftHandSideList:
         del LeftHandSideList[Stmt.group(2)]

   if not Stmt.group(1) in LeftHandSideList:
      LeftHandSideList[Stmt.group(1)] = ReadLine
    
   else:
      OptimizingStatement = LeftHandSideList[Stmt.group(1)]
      LeftHandSideList.update({Stmt.group(1):ReadLine})
      OptimizedFlag = True
      
      #if ConstantVariable in ConstantVariableDict:
      #   del ConstantVariableDict[ConstantVariable]

   if ArgNum == -1:
      if Stmt.group(2) in LeftHandSideList:
         del LeftHandSideList[Stmt.group(2)]

def Compile(SourceCodeName):
   # GCC is Needed 
   Compile = "gcc " + SourceCodeName + "." + sys.argv[1].split(".")[1] + " -o " + SourceCodeName + " -w"
   os.system(Compile)

def Execute(ProgramName, Log):
   Execute = "./" + ProgramName
   if Log:
      Execute += " > " + ProgramName + "[Log].txt"
   os.system(Execute)


try:
   # File Open
   ObfuscatedSourceCode = open(sys.argv[1], 'r', encoding="utf-8")
except:
   print("Invalid Input Source Code!")
   exit()

while True:
   # Source Code Rewriting
   ReadLine = ObfuscatedSourceCode.readline()
   if not ReadLine: break

   LabelAppendedCodeSourceCode.write(ReadLine)
   ReadLineNumber += 1
   CheckFlag=0
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
   ExtractStmt_Arg_S1 = re.match(r'\s*(\S*temp_\d+)\s{1}=\s{1}[\d\s\w\S]*(\S*temp_\d+)[\s\S]*0xFFFFFFFF',ReadLine) # Example :: "temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF;"
   ExtractStmt_Arg_S2 = re.match(r'\s*(\S*temp_\d+)\s{1}=\s{1}[\d\s\w\S]*(\S*temp_\d+)[\d\s\w\S]*(\S*temp_\d+)[\d\s\w\S]*(\S*temp_\d+)',ReadLine) # Example :: X            
   ExtractStmt_Arg1 = re.match(r"\s*(\S*temp_\d+)\s{1}=\s{1}\W*\s?\D*\W*(\d+)u;", ReadLine) # Example :: "temp_85 = (unsigned int)1351u;"
   ExtractStmt_Arg2_1 = re.match(r"\s*(\S*temp_\d+)\s{1}=\s{1}(\S*temp_\d+);", ReadLine) # Example :: "*temp_77 = temp_37;"
   ExtractStmt_Arg2_2 = re.match(r"\s*(\S*temp_\d+)\s{1}=\s{1}[\s\w\D]*(temp_\d+)\s?\S*\s?\w*\s?\S?;", ReadLine) # Example :: "temp_77 = ( unsigned int * )(temp_57);"
   ExtractStmt_Arg3 = re.match(r"\s*(\S*temp_\d+)\s{1}=\s{1}(\S*temp_\d+)\s?\S+\s?(\S*temp_\d+)\s?\S?;", ReadLine) # Example :: "temp_84 = temp_84 * temp_85;"

   if(ExtractStmt_Arg_S1):
      CheckFlag+=1
   if(ExtractStmt_Arg_S2):
      CheckFlag+=1
   if(ExtractStmt_Arg1):
      CheckFlag+=1
   if(ExtractStmt_Arg2_1):
      CheckFlag+=1
   if(ExtractStmt_Arg2_2):
      CheckFlag+=1
   if(ExtractStmt_Arg3):
      CheckFlag+=1

   if(CheckFlag!=1):
      print("Extract Argument Error "+str(CheckFlag))

   if ExtractFunction1: # Extract Pattern :: // Obfuscator generated function
      FunctionFlag1 = True

   if ExtractFunction2 and FunctionFlag1: # Extract Pattern :: static void omni_global_function
      FunctionFlag2 = True

   if FunctionFlag2:
      if ExtractLabel:
         RecordFlag = True
         SettingFlag = True # Label Extracted :: Insert Label Box
         LabelAppendedCodeSourceCode.write(" "*(len(ReadLine)-len(ExtractLabel.group(1))-2) + "printf(\"" + ExtractLabel.group(1) + "\\n" + "\");" + "\n")
         RecordIndex = ExtractLabel.group(1)[1:] # Label Number Extraction
         LabelList.append(RecordIndex) # Label Number Append

      if ExtractStmt_Arg3:
         StmtAnalysis(ExtractStmt_Arg3, 3)

      elif ExtractStmt_Arg2_1:
         StmtAnalysis(ExtractStmt_Arg2_1, 2)

      elif ExtractStmt_Arg2_2:
         StmtAnalysis(ExtractStmt_Arg2_2, 2)

      elif ExtractStmt_Arg1:
         StmtAnalysis(ExtractStmt_Arg1, 1)

      elif ExtractStmt_Arg_S1:
         StmtAnalysis(ExtractStmt_Arg_S1, -1)

      elif ExtractStmt_Arg_S2:
         StmtAnalysis(ExtractStmt_Arg_S2, -2)

      if SettingFlag:
         LabelDict[RecordIndex] += ReadLine
         if OptimizedFlag:
            LabelDict[RecordIndex] = LabelDict[RecordIndex].replace(OptimizingStatement, '')
            OptimizedLineCounter += 1
            OptimizingStatement = ''
            OptimizedFlag = False

         if ConstantPropagationFlag:
            LabelDict[RecordIndex] = LabelDict[RecordIndex].replace(ConstantStatement+"\n", '')
            ConstantPropagationFlag = False
            ConstantOptimizationCounter += 1
            
      if ExtractGoto or ExtractReturn or ExtractThrow:
         # Initialize Left Arguments List
         LeftHandSideList = defaultdict(lambda: "")
         SettingFlag = False

   if not RecordFlag:
      OptimizedSourceCode.write(ReadLine)

LabelAppendedCodeSourceCode.close()
ObfuscatedSourceCode.close()

Compile(LabelAppendedCodeName)
Execute(LabelAppendedCodeName, True)

try:
   LogFile = open(LabelAppendedCodeName + "[Log].txt", 'r')
except:
   print("Invalid Input Log File!")

UsedLabel = []
TotalLabel = []

while True:
   LogReadLine = LogFile.readline()
   if not LogReadLine: break
   CheckLabel = re.match('\w*L(\d+)', LogReadLine)
   if(CheckLabel):
      TotalLabel.append(CheckLabel.group(1))
      if not CheckLabel.group(1) in UsedLabel:
         UsedLabel.append(CheckLabel.group(1))
      LabelCounter[CheckLabel.group(1)] += 1

DispatcherLabel = max(LabelCounter, key=LabelCounter.get)

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

print("### DeadCode Elimination Round", OptimizationRound, ":", OptimizedLineCounter, "Line Optimized ###")
print("### Constant Propagation Round", OptimizationRound, ":", ConstantOptimizationCounter, "Line Optimized ###")

'''
while True:
   if ConstantOptimizationCounter > 0:
      try:
         # File Open
         ObfuscatedSourceCode = open(OptimizedCodeNam + "." + sys.argv[1].split(".")[1], 'r', encoding="utf-8")
      except:
         print("Invalid Input Source Code!")
         exit()

      LeftHandSideList.clear()
      ConstantVariableDict.clear()
      ReadLineNumber = 0
      ConstantOptimizationCounter = 0
      OptimizedLineCounter = 0
      OptimizationRound += 1
      FunctionFlag1 = False
      FunctionFlag2 = False
      OptimizedCodeName = sys.argv[1].split(".")[0] + "_[OptimizedCode][" + str(OptimizationRound) + "Round]"
      OptimizedSourceCode = open(OptimizedCodeName + "." + sys.argv[1].split(".")[1], 'w')
      StmtSet = []

      while True:
         # Source Code Rewriting
         ReadLine = ObfuscatedSourceCode.readline()
         if not ReadLine: break
         StmtSet.append(ReadLine)

         ReadLineNumber += 1

         # Regular Expression
         # Extract Function
         ExtractFunction1 = re.match(r'\/\/ Obfuscator generated function', ReadLine) # Extract Function 1
         ExtractFunction2 = re.match(r'static void omni_global_function', ReadLine) # Extract Function 2

         # Extract Statement
         ExtractStmt_Arg_S1 = re.match(r'\s*(\S*temp_\d+)\s{1}=\s{1}[\d\s\w\S]*(\S*temp_\d+)[\s\S]*0xFFFFFFFF',ReadLine) # Example :: "temp_117 = ( unsigned int )( ( size_t )( ( temp_84 ) & 0xFFFFFFFF;"
         ExtractStmt_Arg_S2 = re.match(r'\s*(\S*temp_\d+)\s{1}=\s{1}[\d\s\w\S]*(\S*temp_\d+)[\d\s\w\S]*(\S*temp_\d+)[\d\s\w\S]*(\S*temp_\d+)',ReadLine) # Example :: X            
         ExtractStmt_Arg1 = re.match(r"\s*(\S*temp_\d+)\s{1}=\s{1}\W*\s?\D*\W*(\d+)u;", ReadLine) # Example :: "temp_85 = (unsigned int)1351u;"
         ExtractStmt_Arg2_1 = re.match(r"\s*(\S*temp_\d+)\s{1}=\s{1}(\S*temp_\d+);", ReadLine) # Example :: "*temp_77 = temp_37;"
         ExtractStmt_Arg2_2 = re.match(r"\s*(\S*temp_\d+)\s{1}=\s{1}[\s\w\D]*(temp_\d+)\s?\S*\s?\w*\s?\S?;", ReadLine) # Example :: "temp_77 = ( unsigned int * )(temp_57);"
         ExtractStmt_Arg3 = re.match(r"\s*(\S*temp_\d+)\s{1}=\s{1}(\S*temp_\d+)\s?\S+\s?(\S*temp_\d+)\s?\S?;", ReadLine) # Example :: "temp_84 = temp_84 * temp_85;"

         if ExtractFunction1: # Extract Pattern :: // Obfuscator generated function
            FunctionFlag1 = True

         if ExtractFunction2 and FunctionFlag1: # Extract Pattern :: static void omni_global_function
            FunctionFlag2 = True

         if FunctionFlag2:

            if ExtractStmt_Arg3:
               StmtAnalysis(ExtractStmt_Arg3, 3)

            elif ExtractStmt_Arg2_1:
               StmtAnalysis(ExtractStmt_Arg2_1, 2)

            elif ExtractStmt_Arg2_2:
               StmtAnalysis(ExtractStmt_Arg2_2, 2)

            elif ExtractStmt_Arg1:
               StmtAnalysis(ExtractStmt_Arg1, 1)

            elif ExtractStmt_Arg_S1:
               StmtAnalysis(ExtractStmt_Arg_S1, -1)

            elif ExtractStmt_Arg_S2:
               StmtAnalysis(ExtractStmt_Arg_S2, -2)

            if OptimizedFlag:
               if OptimizingStatement in StmtSet:
                  StmtSet.remove(OptimizingStatement)
                  print(ReadLineNumber, OptimizingStatement)
                  OptimizedLineCounter += 1
                  OptimizingStatement = ''
                  OptimizedFlag = False

            if ConstantPropagationFlag:
               if ConstantStatement in StmtSet:
                  StmtSet.remove(ConstantStatement)
                  ConstantOptimizationCounter += 1
                  ConstantStatement = ''
                  ConstantPropagationFlag = False

      for i in StmtSet:
         OptimizedSourceCode.write(i)

      ObfuscatedSourceCode.close()
      OptimizedSourceCode.close()
      print("\n### DeadCode Elimination Round", OptimizationRound, ":", OptimizedLineCounter, "Line Optimized ###")
      print("### Constant Propagation Round", OptimizationRound, ":", ConstantOptimizationCounter, "Line Optimized ###")

   else: break
'''

print("\n### Obfuscated Source Code Rewriting Complete ###")
print("### Execution Result of Optimized Program ###\n")
Compile(OptimizedCodeName)
Execute(OptimizedCodeName, False)