# Bhatta, Yubaraj
# yxb4124
# 2019-02-25
#--------------------------------------------------
import re
import sys

#--------------------------------------------------
def processToken( token ) :
   FPP =re.compile("^[0-9]+[)][(][0-9]+$")
   STR = re.compile("^[|][0-9A-Z]*[+]$")
   INT = re.compile("^[#][r-wR-W0-9]+$")
   if FPP.match(token):
     print( '>%s< matches FP' % ( token ) )
   elif STR.match(token):
     print( '>%s< matches STR' % ( token ) )
   elif INT.match(token): 
     print( '>%s< matches INT' % ( token ) )
   else:
      print( '>%s< does not match' % ( token ) )
 #--------------------------------------------------
def main() :
  fName = sys.argv[ 1 ]
  print( 'processing tokens from ' + fName + ' ...' )

  with open( fName, 'r' ) as fp :
    lines = fp.read().replace( '\r', '' ).split( '\n' )

  for line in lines :
    for token in line.split() :
      processToken( token )

#--------------------------------------------------
if ( __name__ == '__main__' ) :
  main()

#--------------------------------------------------
