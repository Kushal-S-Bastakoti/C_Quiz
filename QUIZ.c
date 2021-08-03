#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int*  random_array(); // Generates 15 random numbers

int genetate_correct_answer(int,int);
void generate_question(int,int); // Generates question for the category
int category_selection();

// Driver program
int main(void)
{
	int * question_array;
	int i,category,score=0,score_counter,q, play_again=1;
	int answer_list[15];
	int correct_answer[15];
	
	printf("\n-----------------------------------------------------------------------------------------------\n");
	printf("Welcome to the Quiz\n");
	printf("Play on any the categories \n");
	printf("You have two lives for each level\n");
	printf("Pass the easy level to play the medium level and pass the mdedium level to play hard level\n\n");
	printf("\n-----------------------------------------------------------------------------------------------\n");
	
	
	
	
	
	
	while (play_again){
		
		score=0;
		question_array = random_array();
		category=category_selection();
		
		//Program to ask 15 questions
		for (i=0;i<15;i++)
		{
			//To check score for every 5 questions- done to simulate level: easy, medium and hard
			if(i==0){
				printf("\n-----------------------------------------------------------------------------------------------\n");
				printf("\nEasy Round begins\n");
				printf("\n-----------------------------------------------------------------------------------------------\n");
				score_counter=2; // 2 lives for each level 
			}
			else if(i==5){
				printf("\n-----------------------------------------------------------------------------------------------\n");
				printf("\nMedium Round begins\n");
				printf("\n-----------------------------------------------------------------------------------------------\n");
				score_counter=2;
			}
			else if( i==10){
				printf("\n-----------------------------------------------------------------------------------------------\n");
				printf("\nHard Round begins\n");
				printf("\n-----------------------------------------------------------------------------------------------\n");
				score_counter =2;
			}
		
			//The random question that is to be asked
			q= *(question_array +i);
		
			//Program that prints the question
			generate_question(q,category);
		
			//Program that stores correct answer to the question
		
			correct_answer[i]=generate_correct_answer(q,category);		
		
			//User input to answer
			printf("Please Enter your answer \n");
			scanf("%d", &answer_list[i]);
		
			//Checking if user inputted answer is correct or not
			if(answer_list[i] == correct_answer[i]){
				printf("Correct Answer \n");
				//Score for correct answer
				score++;
			}
			else{
				printf("Wrong Answer\n");
				//Checking life that is amount of wrong answer to be given
				score_counter--;
			}
		
			if (score_counter == 0){
				printf("\n-----------------------------------------------------------------------------------------------\n");
				printf("\nGame Over\n");
				printf("\n-----------------------------------------------------------------------------------------------\n");
				
				printf("Score :\t %d \n Percentage Completed: %d ", score, (i*100)/15);
				
				break;
			}
							
		}
		
		//Winning Condition
		if (i==15 && score_counter != 0){
			printf("\n-----------------------------------------------------------------------------------------------\n");
			printf("\n-----------------------------------------------------------------------------------------------\n");
			printf("\n-----------------------------------------------------------------------------------------------\n");
			printf("You havee won the game!!\n");
			printf("Score :\t %d \n Percentage Completed: %f \n", score, (i*100.0)/15);
			printf("\n-----------------------------------------------------------------------------------------------\n");
			printf("\n-----------------------------------------------------------------------------------------------\n");
			printf("\n-----------------------------------------------------------------------------------------------\n");
		}
		
		printf("Do you want to Play again?\n press 1 if yes \n, 0 if no \n");
		scanf("%d",&play_again);
		
		
	}	
	
	

	return 0;
}

int * random_array()
{
	int static array[15];
	int i,j,k,check;
	srand(time(0));

	for(i = 0; i<5; i++)
	{
		j=rand();
		check =1;
		for (k=0;k<=i;k++){
			if (j == array[k]){
				check =0;
				break;
			}
		}
		if (j>=0 && j < 7 && check != 0) // Easy level questions 0 to 6 
		{
			array[i]=j;
		}
		else{
			i--;
		}
	}
	for(i = 5; i<10; i++)
	{
		j=rand();
		check =1;
		for (k=0;k<=i;k++){
			if (j == array[k]){
				check =0;
				break;
			}
		}
		if (j>=7 && j <= 13 && check != 0) // Medium level question 7 to 13
		{
			array[i]=j;
		}
		else{
			i--;
		}
	}for(i = 10; i<15; i++)
	{
		j=rand();
		check =1;
		for (k=0;k<=i;k++){
			if (j == array[k]){
				check =0;
				break;
			}
		}
		if (j>=14 && j <= 20 && check != 0) // Hard level questions 14 to 20
		{
			array[i]=j;
		}
		else{
			i--;
		}
	}
	
	
	return array;
	
}

int category_selection(){
	int category;
	printf("\n-----------------------------------------------------------------------------------------------\n");
	printf("Please eneter the category of quiz you want to answer\n \t1:science\n\t2:Sports\n\t3:Mixed\n");
	scanf("%d",&category);
	printf("\n-----------------------------------------------------------------------------------------------\n");
	
	return category;
}


int generate_correct_answer(int question , int c){
	int cat1[] = {1,2,3};
	int cat2[] = {1,4,1,3,1,4,1, 3,2,1,1,1,1,1, 2,1,2,3,1,1,1};
	int cat3[] = {1,3,1,1,3,1,1, 1,4,1,2,1,3,1, 2,1,2,3,4,2,4};
	
	if (c==1)
		return cat1[question];
	else if (c ==2 )
		return cat2[question];
	else
		return cat3[question];
}

void generate_question(int question, int c)
{
	switch (c)
	{
		//Case for Science
		case 1:
			switch(question){
				case 0:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("What does DNA stand for?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:Deoxyribo Nucleic acid ");
						printf("\t2:Dehrdyoxyribo Negative acid \n");
						printf("\t3:Dehydratioxyribo Nucleic acid ");
						printf("\t4:Deoxyribo Negative acid \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 1:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("How many bones are in the human body?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:365 ");
						printf("\t2:406 \n");
						printf("\t3:206 ");
						printf("\t4:160 \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 2:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("The concept of gravity was discovered by which famous physicist?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:Albert Einstein ");
						printf("\t2:Sir Isaac Newton \n");
						printf("\t3:Marie Curie ");
						printf("\t4:Galileo Galilei \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 3:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("What is the hardest natural substance on Earth?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:Plastic ");
						printf("\t2:Diamond \n");
						printf("\t3:Graphene ");
						printf("\t4:Steel \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 4:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Which is the main gas that makes up the Earth’s atmosphere?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:oxygen ");
						printf("\t2:hydrogen \n");
						printf("\t3:carbondioxide ");
						printf("\t4:nitrogen \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 5:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("At what temperature are Celsius and Fahrenheit equal?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:40 ");
						printf("\t2:30 \n");
						printf("\t3:-40 ");
						printf("\t4:-30 \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 6:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("What is the biggest planet in our solar system?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:Pluto ");
						printf("\t2:Earth \n");
						printf("\t3:Jupiter ");
						printf("\t4:Saturn \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 7:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("What is given to wood whose normal cells have been replaced with mineral deposits?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:Soft wood");
						printf("\t2:Hard wood \n");
						printf("\t3:Zombie wood ");
						printf("\t4:Petrified wood \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 8:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Pollination by birds is called: ");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:autogamy ");
						printf("\t2:ornithophily \n");
						printf("\t3:entomophily ");
						printf("\t4:anemophily \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 9:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Unlike rodents, the rabbit has how many incisor teeth?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:3 ");
						printf("\t2:4 \n");
						printf("\t3:5 ");
						printf("\t4:6 \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 10:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("What percent of fire-related deaths are due to smoke inhalation rather than burns?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:10%% ");
						printf("\t2:50%% \n");
						printf("\t3:80%% ");
						printf("\t4:99%% \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 11:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("To what familiar fruit is the plantain similar?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:Apple ");
						printf("\t2:Orange \n");
						printf("\t3:Banana ");
						printf("\t4:Grape \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 12:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("How many men have walked on the moon?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:12 ");
						printf("\t2:21 \n");
						printf("\t3:19 ");
						printf("\t4:91 \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 13:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("The fastest-running terrestrial animal is:");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:cheetah ");
						printf("\t2:lion \n");
						printf("\t3:man ");
						printf("\t4:jaguar \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 14:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("In what country do the greatest number of tornadoes occur? ");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:Chile ");
						printf("\t2:Japan \n");
						printf("\t3:Mexico ");
						printf("\t4:US \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 15:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("What wonder drug was used for three years by the Army and Navy before becoming available to the general public in 1944?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:Aspirin ");
						printf("\t2:Penicilin \n");
						printf("\t3:Cocaone ");
						printf("\t4:Paracetamol \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 16:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Which sea is the saltiest natural lake and is also at the lowest elevation on the face of the earth? ");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:Black sea ");
						printf("\t2:Caspian sea \n");
						printf("\t3:Dead sea ");
						printf("\t4:Mariana trench \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 17:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("The scarab, worshipped by the Egyptians, is what type of beetle?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:Scrap beetle ");
						printf("\t2:Stag beetle \n");
						printf("\t3:Sting beetle ");
						printf("\t4:Dung beetle \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 18:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf(".As you go down into a well, your weight:");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:increases slightly  ");
						printf("\t2:decreases slightly \n");
						printf("\t3:remains exactly the same  ");
						printf("\t4:becomes zero \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 19:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("The cloud at ground level is called what? ");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:Dew ");
						printf("\t2:Fog \n");
						printf("\t3:Altocumulus ");
						printf("\t4:Shelf cloud \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 20:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Name the disease of plant in which large yellow spot appears on the leaves?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1:Bacterial Blight ");
						printf("\t2:Bacterial Spot \n");
						printf("\t3:Aphids ");
						printf("\t4:Botrytis \n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}	
			}
			break;
		//case for sports
		case 2:
			switch(question){
				case 0:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("How many players are on the field for each team in an official field hockey match?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: 11");
						printf("\t2: 10\n");
						printf("\t3: 9");
						printf("\t4: 6\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 1:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("In which year was the first European Championship held?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: 1960");
						printf("\t2: 1970\n");
						printf("\t3: 1965");
						printf("\t4: 1958\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 2:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Which country won the first ever Wc in 1930?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Uruguay");
						printf("\t2: Brazil\n");
						printf("\t3: Argentina");
						printf("\t4: Spain\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 3:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("What was the original name of volleyball?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Lacrosse");
						printf("\t2: Big ball\n");
						printf("\t3: Mintonette");
						printf("\t4: smackball\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 4:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("How many players are on each team in the volleyball court?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: 6");
						printf("\t2: 4\n");
						printf("\t3: 3");
						printf("\t4: 10\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 5:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Which football club won fifa wc 2020?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Juventus fc");
						printf("\t2: Fc Barcelona\n");
						printf("\t3: Man utd");
						printf("\t4: Bayern munich\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 6:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("When was the english premier league founded?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: 1992");
						printf("\t2: 1980\n");
						printf("\t3: 1999");
						printf("\t4: 1987\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 7:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("In which year was the first Paralympic games was held?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: 1940");
						printf("\t2: 1944\n");
						printf("\t3: 1948 ");
						printf("\t4: 1952\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 8:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Which country was the host of the first cricket wc?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Australia");
						printf("\t2: England\n");
						printf("\t3: Nz");
						printf("\t4: Canada\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 9:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Which sports? Japanese version is ?hanetsuki??");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Badminton");
						printf("\t2: Polo\n");
						printf("\t3: Fencing");
						printf("\t4: Golf\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 10:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Which team won the first premier league title? ");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Man utd");
						printf("\t2: Chelsea\n");
						printf("\t3: Liverpool fc");
						printf("\t4: Arsenal fc\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 11:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Which club has won the most champions league titles?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Real madrid");
						printf("\t2: Liverpool fc\n");
						printf("\t3: Arsenal fc");
						printf("\t4: Chelsea\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 12:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Who is he first manager who first named David beckham as england?s captain?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Peter taylor");
						printf("\t2: Sam allardye\n");
						printf("\t3: Joe Kinnear");
						printf("\t4: Steve bruce\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 13:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("What does the Olympic flame symbolize?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Continuity");
						printf("\t2: Integrity\n");
						printf("\t3: Challenges");
						printf("\t4: zeal\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 14:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Birdie and eagle are two terms related to which of the following sports?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Polo");
						printf("\t2: Golf\n");
						printf("\t3: Chess");
						printf("\t4: Billiards\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 15:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("he word ?agricultural shot? is known to be used sometimes in which sports?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Cricket");
						printf("\t2: Hockey\n");
						printf("\t3: Golf");
						printf("\t4: Polo\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 16:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Who won the Australian open 2020 men?s singles title?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Rafel nadal");
						printf("\t2: Novak Djokovic\n");
						printf("\t3: Dominic thiem");
						printf("\t4: Roges federal\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 17:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("World?s highest polo ground is in");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Kasur");
						printf("\t2: Attock\n");
						printf("\t3: Shandur");
						printf("\t4: Okara\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 18:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Which player with 653 games has made the most premier league apperances?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Gareth barry");
						printf("\t2: Patrick Vieira\n");
						printf("\t3: Richard dunne");
						printf("\t4: Duncan ferguson\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 19:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("In which wc did diego Maradona score his infamous ?hand of god? goal?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Mexico 1986");
						printf("\t2: Spain 1982\n");
						printf("\t3: Italy 1990");
						printf("\t4: Argentina 1978\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 20:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Ronaldo helped Portugal win the European championship in which year?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: 2016");
						printf("\t2: 2020\n");
						printf("\t3: 2012");
						printf("\t 4: 2008\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}	
			}
			break;
		//case for miixed
		case 3:
			switch(question){
				case 0:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("What town does Spongebob squarepants live in?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Bikini botoom");
						printf("\t2: Bluffinnngton\n");
						printf("\t3: O-Town");
						printf("\t4: Rapture\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 1:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Who painted Mona Lisa?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Leonardo Dicaprio");
						printf("\t2: Pablo Picasso\n");
						printf("\t3: Leonardo Davinci");
						printf("\t4: Vincet Vangogh\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 2:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Which metal is heavier?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Gold(");
						printf("\t2: Silver\n");
						printf("\t3: Titanium");
						printf("\t4: Steel\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 3:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("What relationship were Monica and Ross?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Brothers and sisters");
						printf("\t2: Lovers\n");
						printf("\t3: Son and mother");
						printf("\t4: Aunt and nephew\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 4:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Which vitamin is present in citrus fruit?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Vitamin A");
						printf("\t2: Vitamin B\n");
						printf("\t3: Vitamin C");
						printf("\t4: Both A and B\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 5:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("What is Scooby Doo?s full name?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Scoobert Doo");
						printf("\t2: Scooby Dooby Doo\n");
						printf("\t3: Scooby Doo");
						printf("\t4: Doopy Doo\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 6:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("USB stands for?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Universal Serial Bus");
						printf("\t2: Unlimited Serial Bus\n");
						printf("\t3: Universal Service Bus");
						printf("\t4: Unlimited Service Band\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 7:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("What does NAZI stands for?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: National Socialist German Worker?s Party");
						printf("\t2: National Capitalist German Capital Party\n");
						printf("\t3: National Human Rights Violation Party");
						printf("\t4: Deutsche National Communist Party\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 8:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("What is rhino?s horn made up of?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Steel");
						printf("\t2: Nail\n");
						printf("\t3: Bone");
						printf("\t4: Hair\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 9:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("What?s a baby rabbit called?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Kitten");
						printf("\t2: Hares\n");
						printf("\t3: Bunny");
						printf("\t4: Rabbit\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 10:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("From which country do French files originate?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Germany");
						printf("\t2: Belgium\n");
						printf("\t3: Italy");
						printf("\t4: Spain\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 11:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("How many months have 28 days in them?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: All of them");
						printf("\t2: 3\n");
						printf("\t3: 1");
						printf("\t4: 2\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 12:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("What animal can?t stick out it?s tongue?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Rabbit");
						printf("\t2: Duck\n");
						printf("\t3: Crocidle");
						printf("\t4: Platypus\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 13:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Which color is Girrafe?s tongue?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Blue-black");
						printf("\t2: Red\n");
						printf("\t3: Black");
						printf("\t4: White\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 14:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("What is opposite of Déjà vu?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Treja-Vu");
						printf("\t2: Jamais-Vu\n");
						printf("\t3: Inception Vu");
						printf("\t4: Vu Jade\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 15:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("Which of the following statement is correct?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: 1KB=1024 bytes");
						printf("\t2: 1MB=2048 bytes\n");
						printf("\t3: 1MB=1000 kilobytes");
						printf("\t4: 1KB= 1000 bytes\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 16:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("What is Joe Biden?s middle name?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Robertte");
						printf("\t2: Robinette\n");
						printf("\t3: Robert");
						printf("\t4: Robinson\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 17:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("When was first computer invented?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: 1950");
						printf("\t2: 1944\n");
						printf("\t3: 1956");
						printf("\t4: 1948\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 18:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("If you dug a hole through the center of earth starting from Wellington in Newzealand,\n which European country would you end up in?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Russia");
						printf("\t2: UK\n");
						printf("\t3: German");
						printf("\t4: Spain\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 19:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("What is the metal that gives name to 70th weddind anniversary?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: Ruby");
						printf("\t2: Platinum\n");
						printf("\t3: Silver");
						printf("\t4: Diamond\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}
				case 20:
					{
						
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("How many legs does butterfly have?");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						printf("\t1: The  butterfly doesnot have legs");
						printf("\t2: 2\n");
						printf("\t3: 4");
						printf("\t4: 6\n");
						printf("\n-----------------------------------------------------------------------------------------------\n");
						break;
					}	
			}
			break;
			
			
	}
	
}
