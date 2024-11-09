import java.util.Scanner;
import java.io.FileReader;
import java.io.IOException;

public class a4main{

	public static void main(String[] args)
	{
		//Precondition - Nothing
		//Postcondition - The Wumpus Game has been played
		
		System.out.println("Welcome to **Hunt The Wumpus!**");

		String inFile = "Wumpus.txt";
		
		Scanner inputFileScanner;
	
		Scanner inputMove = new Scanner(System.in);
		
		System.out.println("");
		
		int currentRoom = 1;
		
		int MoveTo = 0;
		
		int Shoot = 0;
		
		int arrows = 3;
		
		boolean wumpus;
		
		boolean spiders;
		
		boolean spiders2;
		
		boolean Pit;
		
		boolean Pit2;
		
		boolean Lose = false;
	
		boolean End = false;
	
		Room roomArr[] = null;
	
		try
		{
			inputFileScanner = new Scanner(new FileReader(inFile));
			
			while(inputFileScanner.hasNextLine())
			{
				int roomAmt = 0;
				roomAmt = inputFileScanner.nextInt();
				roomArr = new Room[roomAmt];
				
				int Roomnum;
				int Adj1;
				int Adj2;
				int Adj3;
				String Description;
				
				for (int i=0; i < roomAmt; i++)
				{	
				Roomnum = inputFileScanner.nextInt();
				Adj1 = inputFileScanner.nextInt();
				Adj2 = inputFileScanner.nextInt();
				Adj3 = inputFileScanner.nextInt();
				inputFileScanner.nextLine();
				Description = inputFileScanner.nextLine();
				
				roomArr[i] = new Room();
				roomArr[i].RoomNum(Roomnum);
				roomArr[i].RoomDes(Description);
				roomArr[i].AdjRoom(Adj1,Adj2,Adj3);
				roomArr[i].getAdjRoom1();
				roomArr[i].getAdjRoom2();
				roomArr[i].getAdjRoom3();
				
				}
				
			}
			
			inputFileScanner.close();
		}
		catch(IOException e)
		{
			System.out.println(e);
		}
		
		int max = 9;
		int min = 1;
		int range = max - min + 1;
		int rand1 = 0;
		int rand2 = 0;
		int rand3 = 0;
		int rand4 = 0;
		int rand5 = 0;
		
		roomArr[rand1 = (int)(Math.random() * range) + min].SetWumpus(true);
		
		while(roomArr[rand2].getSpiders() == false)
		{
			roomArr[rand2 = (int)(Math.random() * range) + min].SetSpiders(false);
			if(rand2 != rand1)
			{
				roomArr[rand2].SetSpiders(true);
			}
		}
		while(roomArr[rand3].getSpiders2() == false)
		{
			roomArr[rand3 = (int)(Math.random() * range) + min].SetSpiders2(false);
			if((rand3 != rand2)&&(rand3 != rand1))
			{
				roomArr[rand3].SetSpiders2(true);
			}
		}
		while(roomArr[rand4].getPit() == false)
		{
			roomArr[rand4 = (int)(Math.random() * range) + min].SetSpiders2(false);
			if((rand4 != rand3)&&(rand4 != rand2)&&(rand4 != rand1))
			{
				roomArr[rand4].SetPit(true);
			}
		}
		while(roomArr[rand5].getPit2() == false)
		{
			roomArr[rand5 = (int)(Math.random() * range) + min].SetSpiders2(false);
			if((rand5 != rand4)&&(rand5 != rand3)&&(rand5 != rand2)&&(rand5 != rand1))
			{
				roomArr[rand5].SetPit2(true);
			}
		}
		
		int wrongmove = 0;

		do{
		
		char MorS = ' ';
		int Adj1 = roomArr[currentRoom - 1].getAdjRoom1();
		int Adj2 = roomArr[currentRoom - 1].getAdjRoom2();
		int Adj3 = roomArr[currentRoom - 1].getAdjRoom3();
			
		//do{
			
			if(wrongmove == 0)
			{
				roomArr[currentRoom - 1].PrintRoom(arrows);
				roomArr[currentRoom - 1].PrintException();
			}
			
			if((roomArr[Adj1 - 1].getWumpus() == true)||(roomArr[Adj2 - 1].getWumpus() == true)||(roomArr[Adj3 - 1].getWumpus() == true))
			{	
				System.out.println("You smell some nasty Wumpus!");
			}
			if((roomArr[Adj1 - 1].getSpiders() == true)||(roomArr[Adj2 - 1].getSpiders() == true)||(roomArr[Adj3 - 1].getSpiders() == true))
			{
				System.out.println("You hear a faint clicking noise.");
			}
			if((roomArr[Adj1 - 1].getSpiders2() == true)||(roomArr[Adj2 - 1].getSpiders2() == true)||(roomArr[Adj3 - 1].getSpiders2() == true))
			{
				System.out.println("You hear a faint clicking noise.");
			}
			if((roomArr[Adj1 - 1].getPit() == true)||(roomArr[Adj2 - 1].getPit() == true)||(roomArr[Adj3 - 1].getPit() == true))
			{
				System.out.println("You smell a dank odor.");
			}
			if((roomArr[Adj1 - 1].getPit2() == true)||(roomArr[Adj2 - 1].getPit2() == true)||(roomArr[Adj3 - 1].getPit2() == true))
			{
				System.out.println("You smell a dank odor.");
			}
			
			System.out.println("(M)ove or (S)hoot?");
			
			MorS = inputMove.next().charAt(0);
			
			if((MorS == 'M')||(MorS == 'm'))
			{
				System.out.println("Which Room?");
				
				MoveTo = inputMove.nextInt();
				
				if((MoveTo != Adj1) && (MoveTo != Adj2) && (MoveTo != Adj3))
				{
					wrongmove++;
					System.out.println("Dimwit! You can't get to there from here.");
					roomArr[currentRoom - 1].PrintException();
				}	
				else
				{			
					wrongmove = 0;
					currentRoom = MoveTo;
					
					if(roomArr[currentRoom - 1].getWumpus() == true)
					{
						End = true;
						Lose = true;						
					}
					else if(roomArr[currentRoom - 1].getWumpus() == true)
					{
						End = true;
						Lose = true;
					}
					else if(roomArr[currentRoom - 1].getSpiders() == true)
					{
						End = true;
						Lose = true;
					}
					else if(roomArr[currentRoom - 1].getSpiders2() == true)
					{
						End = true;
						Lose = true;
					}
					else if(roomArr[currentRoom - 1].getPit() == true)
					{
						End = true;
						Lose = true;
					}
					else if(roomArr[currentRoom - 1].getPit2() == true)
					{
						End = true;
						Lose = true;
					}
				}
			}
			
			else if((MorS == 'S')||(MorS == 's'))
			{
				System.out.println("Which Room?");
				
				Shoot = inputMove.nextInt();
				
				if((Shoot != Adj1) && (Shoot != Adj2) && (Shoot != Adj3))
				{
					wrongmove++;
					System.out.println("Dimwit! You can't get to there from here.");
					roomArr[currentRoom - 1].PrintException();
				}
				else
				{
					wrongmove = 0;
					arrows--;
					
					if(arrows == 0)
					{
						End = true;
						Lose = true;
					}
					
					if(Shoot == rand1 + 1)
					{
						End = true;
						Lose = false;
					}
					else
					{
						System.out.println("Your arrow goes down the tunnel and is lost. You missed.");
					}
				}
			}
					
		}while(End == false);
		
		if(Lose == true)
		{
			if(arrows == 0)
			{
				System.out.println("You ran out of Arrows! Game Over.");
			}
			else
			{
				System.out.println("You Died! Game Over.");	
			}
		}
		else
		{
			System.out.println("Your arrow goes down the tunnel and finds its mark!");
			System.out.println("You shot the Wumpus! **You Win!**");
			System.out.println("Enjoy your fame!");
		}
	}
}