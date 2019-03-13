// Bhatta, Yubaraj
// yxb4124
// 2019-02-25

using System;
using System.IO;
using System.Text.RegularExpressions;

public class hmwk_03
{
  static public void processToken( string token ) {
   
    Regex FPP = new Regex(@"^[0-9]+[)][(][0-9]+$");
    Regex STR = new Regex (@"^[|][A-Z0-9]*[+]$");
    Regex INT = new Regex(@"^[#][0-9r-wR-W]+$"); 
    if (FPP.IsMatch(token)) 
    
      Console.WriteLine(">" + token + "< matches FP");
    
    else if (STR.IsMatch(token))
    
     Console.WriteLine(">" + token + "< matches STR");
    
    else if (INT.IsMatch(token))
    
      Console.WriteLine(">" + token + "< matches INT");
    
     else
     
      Console.WriteLine(">" + token + "< does not match");
     
    
  }
  static public void Main( string[] args )
  {
    Console.WriteLine( "processing tokens from " + args[ 0 ] + " ..." );

    foreach ( string line in File.ReadAllLines( args[ 0 ] ) ) {
      foreach ( string token in line.Split( (char []) null, StringSplitOptions.RemoveEmptyEntries ) ) {
        processToken( token );
      }
    }
  }
}
