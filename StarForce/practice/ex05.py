import re

a="    temp_143 = temp_136[ temp_141 ];"
b="	temp_146 = temp_146 + temp_140;"
if re.match(r"\s*temp_\d+\s*=\s*temp_\d+\[\s*temp_\d+\s*\]\s*;\s*",a):
	print(re.match(r"\s*temp_\d+\s*=\s*temp_\d+\[\s*temp_\d+\s*\]\s*;\s*",a))
	print("YAHO")
if re.match(r"\s*temp_\d+\s*=\s*temp_\d+\[\s*temp_\d+\s*\]\s*;\s*",b):
	print(re.match(r"\s*temp_\d+\s*=\s*temp_\d+\[\s*temp_\d+\s*\]\s*;\s*",b))
	print("HOUA")
