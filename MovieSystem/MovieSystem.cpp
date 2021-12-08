#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

class Movie {
private :
	int id;
	string name;
	float point;
	int year;
	
	public:
		Movie(){}

	
	public:
		Movie(int id,string name,float point,int year){
		this->id=id;
		this->name=name;
		this->point=point;
		this->year=year;	
	}
	


								
	int getId(){
		return id;
	 }
	
	string getName(){
		return name;		
	}
		
	float getPoint(){
		return point;
	}
	
	int getYear(){
		return year;
	}
	
	void setPoint(float new_point){
		point = new_point;
	}
	
	void setYear(int new_year){
		year = new_year;
	}
	void setName(string new_name){
		name = new_name;
	}
	void setId(int new_id){
		id = new_id;
	}
	
	 					
	void printMovie() {
	    cout << "Id : " << id << " Name : " << name << " Point : " << point << "Year : "<<year<<endl;
	}
 };
 
 
 
 void movieById(Movie* movie_list[]){
 	int id;
 	cout<<"Enter the Id of Movie"<<endl;
 	cin>>id;
 	 	
	for(int i= 0; sizeof(movie_list)/sizeof(movie_list[0]);i++){
		
		if(id==movie_list[i]->getId()){
			movie_list[i]->printMovie();
			
		 }
	 }		 	
 }
				
		
		
	
void between_the_years_movies(int year1, int year2 , Movie* movie_list[] ){
	
	int i ;

	for(i= 0; sizeof(movie_list)/sizeof(movie_list[0]);i++){
		
		if(year1<= movie_list[i]->getYear() && movie_list[i]->getYear() <= year2 ){		
		movie_list[i]->printMovie();
		
		
	}	

  }
				
}


void change_the_point(int id, float new_point, Movie* movie_list[]){   // change the movie point with the ID OF MOVIE . Enter the new point like parameter in the function
	 
	 
		
	for(int i= 0; sizeof(movie_list)/sizeof(movie_list[0]);i++){
		
	  if(id==movie_list[i]->getId()){
	  		cout<<"Movie point is : "<< movie_list[i]->getPoint();  // before the changing value 
			movie_list[i]->setPoint(new_point);
			movie_list[i]->printMovie();
			
		 } 		
	}
	
}


void  get_movie_details_starting_letter(char  letter ,Movie* movie_list[]){
	
	for(int i= 0; sizeof(movie_list)/sizeof(movie_list[0]);i++){
		
	  if(letter==movie_list[i]->getName().at(0)){
			movie_list[i]->printMovie();
			
		 } 		
	}
	
	
}

void voting_system(int id,int votecount,Movie* movie_list[]){
		Movie* movie ;
		int i =0;
		int avg;
	
		for( i= 0; sizeof(movie_list)/sizeof(movie_list[0]);i++){
		
		if(id == movie_list[i]->getId()){		
		 movie = movie_list[i];		
	
		 }			
 	}
 	 int vote_point;
	 int sum = 0;
	 for( i = 0; i<votecount; i++){
	 	
	 	cout<<"Please enter your vote: "<<endl;
	 	cin>>vote_point;
	 	sum = sum+ vote_point;
	 }	
	 
	 sum = sum+ movie->getPoint();
	avg=sum/i+2; // because of the i+1 for the i start fromn 0 and other +1 = i+2 comes from old point sothat we added the +1 = i+2
	movie->setPoint(avg);
	 cout<<"new movie VOTE SCORE IS : "<<avg<<endl;
	 movie->printMovie();
}

int main(){

	int id=1;
	string name;
	string point;
	string year;

	int counter = 0;
	
	ifstream read_file;
	string line;
	read_file.open("movies.txt");
	
	if(!read_file.is_open()){
		cerr<<" file could not be opened"<<endl;
		exit(1);
	}
	
	Movie* movie_list[250];
	while(getline(read_file,line)){
		stringstream line_stream(line);

        getline(line_stream, point, ';');
        getline(line_stream, name, '(');
        getline(line_stream, year, ')');
		

		int integer_year = stoi(year);
		float float_point = stof(point);

        Movie *movies= new Movie(id,name,float_point,integer_year);
        movie_list[counter]=movies;
        counter++;
        id++;
		
		cout<<"Id : "<<id<<"name: "<<name<<"point"<<point<<"year : "<<year<<endl;	
	}
	read_file.close();
	
	
	
	int user_selection;
	
	
	
		
	cout<<"Welcome to the Movie Market"<<endl;
	cout<<"Plese enter the 1 to gettting  movie details by ID "<<endl;
	cout<<"Plese enter the 2 to listing movies between the years entered "<<endl;
	cout<<"Plese enter the 3 to changing the point of a movie "<<endl;
	cout<<"Plese enter the 4 to getting movie details starting with the entered letter "<<endl;
	cout<<"Plese enter the 5 to using  VOTESYSTEM "<<endl;
	cout<<"Plese enter the EXIT to exit "<<endl;
	
	cin>>user_selection;
	

    // Switch case applicable
	if(user_selection==1){
		movieById(movie_list);
	}
	
	else if(user_selection==2){
		cout<<"Enter the years which wanted between the years  "<<endl;
		between_the_years_movies(1990,2010,movie_list);
	}
	
	else if(user_selection==3){
		cout<<"Enter the name of movie to changing point "<<endl;
		change_the_point(5,8.6,movie_list);
	}
	
	else if(user_selection==4){
		cout<<"when the entering letter PLEASE USE CAPITALS  "<<endl;
		
		char first_char;
		cout<<"Enter the first letter to listing movies details "<<endl;
		cin>>first_char;
		get_movie_details_starting_letter(first_char,movie_list);
	}
	
	else if(user_selection == 5 ){
		cout<<"Enter the  vote points "<<endl;
		voting_system(23,5,movie_list);
	}
	
	if(user_selection==0){
		exit(1);
	}
	
}













