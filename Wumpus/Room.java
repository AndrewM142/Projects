public class Room{

	int Roomnum;
	String Description;
	int Adj1;
	int Adj2;
	int Adj3;
	boolean wumpus;
	boolean spiders;
	boolean spiders2;
	boolean Pit;
	boolean Pit2;
	int arrows = 3;	
	
	public void WumpusIn(){
		
	//Precondtion - wumpus variable created
	//Postcondition - Wumpus variable set to false
	
	wumpus = false;
	}
	
	public void SpiderIn(){
	
	//Precondtion - spiders variable created
	//Postcondition - spiders variable set to false
	
	spiders = false;
	}
	
	public void PitIn(){
	
	//Precondtion - Pit variable created
	//Postcondition - Pit variable set to false
	
	Pit = false;
	}
	
	public void SpiderIn2(){
		
	//Precondtion - spiders2 variable created
	//Postcondition - spiders2 variable set to false	
	
	spiders2 = false;
	}
	
	public void PitIn2(){
		
	//Precondtion - Pit2 variable created
	//Postcondition - Pit2 variable set to false	
	
	Pit2 = false;
	}	
	
	public void SetWumpus(boolean wumpusTF){
		
	//Precondtion - wumpus variable created
	//Postcondition - Wumpus variable can associate with nain
		
	wumpus = wumpusTF;
	}
	public void SetSpiders(boolean spidersTF){
		
	//Precondtion - spiders variable created
	//Postcondition - spiders variable can associate with main
		
	spiders = spidersTF;	
	}
	public void SetSpiders2(boolean spidersTF2){
	
	//Precondtion - spiders2 variable created
	//Postcondition - spiders2 variable can associate with main
	
	spiders2 = spidersTF2;		
	}
	public void SetPit(boolean PitTF){
	
	//Precondtion - Pit variable created
	//Postcondition - Pit variable can associate with main
	
	Pit = PitTF;
	}
	public void SetPit2(boolean PitTF2){
	
	//Precondtion - Pit variable created
	//Postcondition - Pit variable can associate with main
	
	Pit2 = PitTF2;
	}
	public void RoomNum(int num){
	
	//Precondtion - Roomnum variable created
	//Postcondition - Roomnum variable can associate with main
		
	Roomnum = num;	
	}
	public void loseArrows(int number){
	
	//Precondtion - arrows variable created 
	//Postcondition - arrows variable can associate with main
	
	arrows = number;
	}
	public void AdjRoom(int adj1, int adj2, int adj3){
		
	//Precondtion - Adj1,Adj2,Adj3 variables created
	//Postcondition - Adj1,Adj2,Adj3 variables can associate with main
		
	Adj1 = adj1;
	Adj2 = adj2;
	Adj3 = adj3;

	}
	public void RoomDes(String Des){
	
	//Precondtion - Description variable created
	//Postcondition - Description variable can associate with main
	
	Description = Des;
	}
	public void PrintRoom(int arrows){
	
	//Precondition - arrows,Roomnum,Description brought to Room class
	//Postcondition - Following statements will be printed if function is called
	
	System.out.println("You are in room " + Roomnum);
	System.out.println("You have "+arrows+" arrows left");
	System.out.println(Description);
	}
	public void PrintException(){
		
	//Precondtion - Adj1,Adj2,Adj3 brought to Room class
	//Postcondition - Following statement will be printed if function is called
	
	System.out.println("There are tunnels to rooms "+Adj1+", "+Adj2+", "+Adj3+".");
	}
	public int getAdjRoom1(){

	//Precondtion - Adj1 brought to Room class
	//Postcondition - Adj1 returned to main
	
	return Adj1;
	}
	public int getAdjRoom2(){

	//Precondtion - Adj2 brought to Room class
	//Postcondition - Adj2 returned to main

	return Adj2;
	}
	public int getAdjRoom3(){
		
	//Precondtion - Adj3 brought to Room class
	//Postcondition - Adj3 returned to main	
		
	return Adj3;
	}
	public boolean getWumpus(){
	
	//Precondtion - wumpus brought to Room class
	//Postcondition - wumpus returned to main
	
	return wumpus;
	}
	public boolean getSpiders(){
		
	//Precondtion - spiders brought to Room class
	//Postcondition - spiders returned to main
	
	return spiders;	
	}
	public boolean getSpiders2(){
	
	//Precondtion - spiders2 brought to Room class
	//Postcondition - spiders2 returned to main
	
	return spiders2;
	}
	public boolean getPit(){
	
	//Precondtion - Pit brought to Room class
	//Postcondition - Pit returned to main
	
	return Pit;
	}
	public boolean getPit2(){
	
	//Precondtion - Pit2 brought to Room class
	//Postcondition - Pit2 returned to main
	
	return Pit2;
	}
}
