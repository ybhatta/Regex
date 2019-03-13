// Bhatta, Yubaraj
// yxb4124  
// 2019-02-25 

import java.nio.file.Paths;
import java.nio.file.Files;
import java.util.Arrays;

public class hmwk_03 {
  public static void processToken(String token) {
    String FPP = "^[0-9]+[)][(][0-9]+$";
    String STR = "^[|][A-Z0-9]*[+]$";
    String INT = "^[#][0-9r-wR-W]+$";

    if (token.equals("")) {
      return;
    }
    if (token.matches(FPP)) {
      System.out.println(">" + token + "<" + " matches FP");
    } else if (token.matches(STR)) {
      System.out.println(">" + token + "<" + " matches STR");
    } else if (token.matches(INT)) {
      System.out.println(">" + token + "<" + " matches INT");
    } else {
      System.out.println(">" + token + "<" + " does not match");
    }

  }

  public static void main(String[] args) {
    System.out.println("processing tokens from " + args[0] + " ...");

    try {
      Files.lines(Paths.get(args[0]))
          .forEachOrdered(line -> Arrays.stream(line.split("\\s+")).forEachOrdered(token -> processToken(token)));
    } catch (java.io.IOException e) {
      e.printStackTrace();
    }
  }
}