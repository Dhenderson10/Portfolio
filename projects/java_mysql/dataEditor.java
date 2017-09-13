
import java.sql.* ;
import java.util.Scanner;
import java.io.* ;
import java.util.Random ;

public class dataEditor {
  public static void main(String[] args) {

  int playerID, age ;
  String name, character1, character2, input = null ;
  boolean user = false;
  Scanner prompt = new Scanner(System.in);

  Connection conn = null ;

  try {
	conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/smashbros?useSSL=false","dan","PASSWD YO FATHA WOULD USE");  


  }
  catch (SQLException ex ) {
  	System.out.println("SQLException: " + ex.getMessage()) ;
  	System.out.println("SQLState: " + ex.getSQLState()) ;
  	System.out.println("VendorError: " + ex.getErrorCode()) ;
  }

  System.out.println("\nPLAYER TABLE EDITING PROGRAM\n");
  System.out.println("Choose an option below \n");
  System.out.println("-d :: calls a query to display the player table");
  System.out.println("-i :: insert a tuple into the table");
  System.out.println("-r :: remove a tuple from the table");
  System.out.println("-e :: end the program");
while(true)
{
  while(user == false)
  {
    System.out.print(">>");
    input = prompt.next();
    if(input.equals("-d") || input.equals("-r") || input.equals("-i") || input.equals("-e"))
    {
      user = true;
    }
    else
    {
      System.out.println(input);
      System.out.println("Not a valid argument");

    }
  }

  if(input.equals("-e"))
  {
    System.exit(0);
  }

  if(input.equals("-i"))
  {
    try
    {
       Statement stmt = null ;
       System.out.print("Insert Player Tuple\nName: ");
       name = prompt.next();
       System.out.print("Character1: ");
       character1 = prompt.next();
       System.out.print("Character2: ");
       character2 = prompt.next();
       System.out.print("age: ");
       age = prompt.nextInt();
       System.out.print("PlayerID: ");
       playerID = prompt.nextInt();

       stmt = conn.createStatement();

       stmt.executeUpdate("insert into player values('" + name + "','" + character1 + "','" + character2 +"','" + age + "','" + playerID +"');");
       stmt.close();
     }

     catch (SQLException ex ) {
        System.out.println("SQLException: " + ex.getMessage()) ;
        System.out.println("SQLState: " + ex.getSQLState()) ;
        System.out.println("VendorError: " + ex.getErrorCode()) ;
      }
      user = false;
  }

  if(input.equals("-r"))
  {
    try
    {
      Statement stmt = null;
      System.out.print("Enter the PlayerID of the tuple you would like to remove: ");
      input = prompt.next();
      stmt = conn.createStatement();
      stmt.executeUpdate("delete from player where PlayerID = " + input);
      stmt.close();



    }


    catch (SQLException ex ) {
        System.out.println("SQLException: " + ex.getMessage()) ;
        System.out.println("SQLState: " + ex.getSQLState()) ;
        System.out.println("VendorError: " + ex.getErrorCode()) ;
      }
      user = false;
  }


  if(input.equals("-d"))
  {
      Statement stmt = null ;
      ResultSet rs = null ;

      try {

        stmt = conn.createStatement() ;
      	rs = stmt.executeQuery("Select * from player where PlayerID < 10") ;

    	while (rs.next() ) {
    	  name = rs.getString("Name") ;
    	  character1 = rs.getString("Character1") ;
    	  character2 = rs.getString("Character2") ;
    	  age = rs.getInt("age") ;
        playerID = rs.getInt("PlayerID") ;
    	  System.out.print("Name: " + name) ;
    	  System.out.print(", Character1: " + character1) ;
    	  System.out.print(", Character2: " + character2) ;
    	  System.out.print(", age: " + age) ;
        System.out.println(", PlayerID: " + playerID) ;
    	}

    	rs.close() ;
    	stmt.close() ;

      }

      catch (SQLException ex ) {
      	System.out.println("SQLException: " + ex.getMessage()) ;
      	System.out.println("SQLState: " + ex.getSQLState()) ;
      	System.out.println("VendorError: " + ex.getErrorCode()) ;
      }
      user = false;
    }
}
  }
}
