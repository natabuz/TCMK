#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
import lint as lib

def Exit():
	print "Для выхода нажмите Enter...\n";
	sys.exit(-1);

if len(sys.argv) != 5 and len(sys.argv) != 6:
	print "\nНеверно заданы параметры командной строки!\n";
	Exit();

binary = False;

a = lib.Lint();
b = lib.Lint();
c = lib.Lint();

if len(sys.argv) == 5:
	num1 = lib.Lint(a.read(sys.argv[1]));
	num2 = lib.Lint(b.read(sys.argv[3]));

	a = num1;
	b = num2;
else:
	binary = True;
	
	a = lib.Lint(a.binread(sys.argv[1]));
	b = lib.Lint(b.binread(sys.argv[3]));

if sys.argv[2] == "+":
	c = a + b;
	result = c.trim().toString(); 
elif sys.argv[2] == "-":
	c = a - b;
	result = c.trim().toString();
elif sys.argv[2] == "x":
	c = a * b;
	result = c.trim().toString();
elif sys.argv[2] == "/":
	if b == lib.Lint("0"):
		print "\nДеление на 0 невозможно!\n";
		Exit();
	else:
		c = a / b;
		result = c.trim().toString();
elif sys.argv[2] == "%":
	if b == lib.Lint("0"):
		print "\nДеление на 0 невозможно!\n";
		Exit();
	else:
		c = a % b;
		result = c.trim().toString();
elif sys.argv[2] == "^":
	if b.isNegative():
		print "\nСтепень не может быть отрицательной!\n";
		Exit();
	else:
		c = a ^ b;
		result = c.trim().toString();
else:
	print "\nНеверная операция!\n";
	Exit();

if binary == False:
	c.write(result, sys.argv[4]);
else:
	c.binwrite(c, sys.argv[4]);