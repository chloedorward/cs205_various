#include "beehive.h"

Beehive::Beehive(string ID,int foNum, int NumOfBoard,int dronNum, double grow)
{

    using namespace std;
growthP = grow;
    hiveID = ID;
 forNum = foNum;
   droneNum = dronNum;
    setNumOfBoards(NumOfBoard);
 randNumGen = (rand() % 10) + 1;

    myfile.open ("example.txt");



}
Beehive::~Beehive(){
    myfile.close();

}
void Beehive::randomSwarm(){
 Attack = true;
 swarm = true;

     int randTime1 = (rand() % 72000) + 21600;
     int randTime2 = (rand() % 72000) + 21600;
     AttackTime = randTime1;
     swarmTime = randTime2;
}
void Beehive::beeSimpleGrowth(double x){
    for (int i=0;i<x;i++) {
        Forager f;


        forageVect.push_back(f);
    }
    forNum +=x;

}
void Beehive::setYearsToRun(int x){
    numofyears = x;
}
void Beehive::setStartingValues(){
    for (int i=0;i<numOfBoards;i++) {
        Board b;
        boardVect.push_back(b);
    }
    for (int i=0;i<forNum;i++) {
        Forager f;


        forageVect.push_back(f);
    }

    for (int i=0;i<0;i++) {
        Worker f;


        workerVect.push_back(f);
    }


    for (int i=0;i<droneNum;i++) {
        Drone d;
        droneVect.push_back(d);
    }


}// need all the starting values


int Beehive::getNumOfYears(){
    return numofyears;
}
void Beehive::setSeason(int x){
    q.setSeason(x);
    season = x;
}
void Beehive::setup(){// need to finish this
    int x=1;


    setYearsToRun(x);

    setStartingValues();// need the starting values

}
void Beehive::OneYearTimeStep(){// check if simulation is over
    for (int i=0;i<12;i++) {
        OneMonthTimeStep();
    }
}
void Beehive::OneMonthTimeStep(){
    // update season
    setSeason(getSeason()+1);
    //////cout<<"additional month complete."<<endl;
    for (int i=0;i<4;i++) {

        OneWeekTimeStep();
    }
}

int Beehive::growthfunction(double x){
    return forNum*x;
}
void Beehive::OneWeekTimeStep(){
    for (int i=0;i<7;i++) {

       //killBees();
       //evolveBees();
       //foodCalculation();
       //birthBees();
       //nurseBees();
      OneDayTimeStep();

        randomSwarm();

        beeSimpleGrowth(growthfunction(growthP));

    }
    cout<<"total bees entering normaly "<<BeeCounter<<"---"<<" total bees exiting normaly "<<exitCounter<<endl;
    cout<<"total bees entering during rob "<<atkC<<"---"<<"total bees exiting durring swarm "<<SWRMC<<endl;
    cout<<"total Enter "<<BeeCounter+atkC<<"---total exit "<<exitCounter+SWRMC<<endl;
}
void Beehive::foodCalculation(){

}

void Beehive::OneDayTimeStep(){//1x day things will need to update

    TOD=0;
    //birth
    //death
    //food calculation
    //evolution
    //nursing
    for (int i=0;i<beeVect.size();i++) {
        beeVect.at(i).setAge(beeVect.at(i).getAge()+86400);


    }



    for (int i=0;i<24;i++) {
        OneHourTimeStep();
    }
    cout<<"day has passed"<<endl;
    cout<<"num of Bees in hive "<<forNum<<endl;
    cout<<"swarmTime today- "<<parseTime(swarmTime)<<endl;
    cout<<"attackTime today- "<<parseTime(AttackTime)<<endl;
    cout<<"num of bees in swarm/rob "<<droneNum<<endl;
    cout<<"bees entering normaly today"<<BeeCounter2<<"---"<<"bees exiting normaly today"<<exitCounter2<<endl;
    cout<<"bees entering during rob today"<<atkC2<<"---"<<"bees exiting durring swarm today"<<SWRMC2<<endl;
   BeeCounter2=0;
   exitCounter2=0;
   atkC2=0;
   SWRMC2=0;
}
void Beehive::OneHourTimeStep(){
    for (int i=0;i<60;i++) {


        OneMinuteTimeStep();

    }
    cout<<currentTime<<endl;
}
void Beehive::OneMinuteTimeStep(){



    for (int i=0;i<60;i++) {
        OneSecondTimeStep();
    }

}
void Beehive::OneSecondTimeStep(){// where a lot of things need to be updated
    currentTime++;
    TOD++;
    if(swarm&& TOD>=swarmTime){
        for (int i=0;i< droneVect.size();i++) {
            SwarmTech(&droneVect.at(i));
        }
        swarm = false;
    }

    if(Attack&& TOD>=AttackTime){

        for (int i=0;i< droneVect.size();i++) {
            attackTech(&droneVect.at(i));
        }

        Attack = false;
    }

    for (int i=0;i< forageVect.size();i++) {


        forageTech(&forageVect.at(i));

    }

    for (int i=0;i< workerVect.size();i++) {
        workerTech(workerVect.at(i));
    }

    //time
    //foragers
    //workers

    //update age


    if(domilli){
        for (int i=0;i<1000;i++) {
            OneMillisecondTimeStep();
        }
    }
}

void Beehive::OneMillisecondTimeStep(){// extra precision if needed
    // manage gates & boards(bees trying to enter/leave the hive
    //make udp messages
    //send the messages


    if(timeSinceMessage>=50){

        updateBoards();

        timeSinceMessage=0;


        if(checkBoards()){


            myfile << hiveID<<"-"<<parseTime(currentTime)<<boardString()<<"\n";



        }
    }
    timeSinceMessage++;


    milliCounter++;
    if(milliCounter > 999){
        milliCounter =0;
    }

}


void Beehive::checkbees(){
    for(int i=0;i<forageVect.size();i++){
        string s=forageVect.at(i).getState();
        ////cout<<i<<"---"<<s<<forageVect.at(i).checkExits()<<endl;
    }
    for(int i=0;i<boardVect.size();i++){
        boardVect.at(i).testFunct();
    }

}

void Beehive::udpSetup(){
    // make a udp message  and send it to the thing
}
void Beehive::updateDatabase(){

}

void Beehive::updateBoards(){


    for(int j=0;j<boardVect.size();j++){

        boardVect.at(j).updateline(TOD);

    }

}
bool Beehive::checkBoards(){

    bool x = false;
    for (int i=0;i<boardVect.size();i++) {
        if (boardVect.at(i).checkBoards() ==0) {

        }
        else {
            //   //cout<<boardVect.at(i).checkBoards()<<"  "<<currentTime<<endl;
            x=true;
        }
    }

    return x;
}
void Beehive::setNumOfBoards(int x){
    numOfBoards =x;
    //initialize the boards in board vect
}


void Beehive::killBees(){
    for (int i=0;i<beeVect.size();i++){
        if(beeVect.at(i).CheckDeath()){

            // need to kill the bee
            //remove from all vectors bee is in
        }
    }

}
void Beehive::birthBees(){
    q.BirthEggs(getSeason(),pollenGen,pollenUsed);

    for (int i=0;i<q.getEgg();i++) {
        Brood b;
        beeVect.push_back(b);
        broodVect.push_back(&b);

    }
    // make a new brood

    // add to broodvect and beevect
    fertilizeEggs();

}
void Beehive::fertilizeEggs(){
    int j=broodVect.size();
    int i=0;
    while(i<q.fertilizeEggs(q.getEgg())){

        broodVect.at(j)->setFert(true);
        j--;
        i++;
    }

}
int Beehive::getSeason(){
    return season;
}
void Beehive::evolveBees(){// this method does not work
    //2,073,600 - 24 days in seconds
    //1,814,400 - 21 days in seconds
    //259,200 - 3 days in seconds



    for(int i=0;i< broodVect.size();i++){

        if(broodVect.at(i)->getFert() == true && beeVect.at(i).getAge() > 1814400){
            // make a juvinile
            // ////cout<<"making a juvinile"<<endl;
            int temp = broodVect.at(i)->getAge();
            for (int var = 0; var < beeVect.size(); ++var) {
                if(&beeVect.at(var) == &*broodVect.at(i)){// this has aproximatly 0.0000001% chance of working, so you will have to fix this
                    //   ////cout<<"found match"<<endl;
                    beeVect.erase(beeVect.begin()+var);
                    break;
                }
            }
            broodVect.erase(broodVect.begin()+i);
            Juvinile j;
            j.setAge(temp);
            beeVect.push_back(j);
            juviVect.push_back(&j);


        }
        else if (beeVect.at(i).getAge() > 2073600){

            int temp = broodVect.at(i)->getAge();

            for (int var = 0; var < beeVect.size(); ++var) {
                if(&beeVect.at(var) == &*broodVect.at(i)){// this has aproximatly 0.0000001% chance of working, so you will have to fix this
                    //  ////cout<<"found match"<<endl;
                    beeVect.erase(beeVect.begin()+var);
                    break;
                }
            }
            broodVect.erase(broodVect.begin()+i);
            Drone d;
            d.setAge(temp);
            beeVect.push_back(d);
            droneVect.push_back(d);
        }
    }



    // check what bee evolves into
    // find exactly what age bee evolves
    // check hive condition for nurses/ foragers/ workers evolution
    // 1/3 hive foragers
    // nurses*2/3 = broods(that need to be nursed) (certain age)

}
void Beehive::setWeather(double x){
    temperature=x;
}
void Beehive::nurseBees(){
    //needs to reset all broods(that need to be nursed)
    //assign a nurse to all those(that need to be nursed)
}
void Beehive::feedBees(){
    // reset bee fed
    // make sure there is enough food to feed all bees
    // dont forget the queen
    //update the pollen and food counts
    // update ratio counts
}
void Beehive::workerTech(Worker w){
    //decide how workers create noise;
}
void Beehive::forageTech(Forager *h){

    // need to create the ai functionality for assigning what state a forager is in

    //if they are in hive between
    if((TOD<=21600||TOD>=72000)||temperature<50){


        if (h->getFor()==true) {
            //////cout<< "bee trying to forage hive  "<<endl;
            forageStep(h);
        }
        else if (h->getNest() == true) {

            returnToNest(h);
        }
        else if (h->getSearch()==true) {

            searchForThing(h);
        }
        else if (h->getEx()==true) {

            explore(h);
        }
        else if (h->getDanceB() == true) {
            //   ////cout<< "bee dancing hive"<<endl;
            beginDance(h);
        }

        else if (h->getEnter() == true) {
            // ////cout<< "bee enter hive"<<endl;
            enterStates(h);
        }
    }
    else{
        if(h->getinit() == true){
            // ////cout<< "bee trying to init  hive  "<<endl;
            hasTarget(h);
        }
        else if (h->getFor()==true) {
            //////cout<< "bee trying to forage hive  "<<endl;
            forageStep(h);
        }
        else if (h->getNest() == true) {

            returnToNest(h);
        }
        else if (h->getSearch()==true) {

            searchForThing(h);
        }
        else if (h->getEx()==true) {

            explore(h);
        }
        else if (h->getDanceB() == true) {
            //   ////cout<< "bee dancing hive"<<endl;
            beginDance(h);
        }
        else if (h->getEat()== true ){

            restOrEat(h);
        }
        else if (h->getEnter() == true) {
            // ////cout<< "bee enter hive"<<endl;
            enterStates(h);
        }
        else if (h->getExit()== true) {
            //////cout<< "bee trying to exit hive  "<<endl;

            exitStates(h);

        }
        else {
            ////cout<<"error in forager state"<<endl;
            ////cout<< "init"<<std::boolalpha<<h->getinit()<<endl;
            ////cout<< "exit"<<std::boolalpha<<h->getExit()<<endl;
            ////cout<< "enter"<<std::boolalpha<<h->getEnter()<<endl;
            ////cout<< "eat"<<std::boolalpha<<h->getEat()<<endl;
            ////cout<< "dance"<<std::boolalpha<<h->getDanceB()<<endl;
            ////cout<< "search"<<std::boolalpha<<h->getSearch()<<endl;
            ////cout<< "nest"<<std::boolalpha<<h->getNest()<<endl;
            ////cout<< "explore"<<std::boolalpha<<h->getEx()<<endl;
            ////cout<< "forage"<<std::boolalpha<<h->getFor()<<endl;
        }

    }

}

// this was a temp method delete this

void Beehive::enterStates(Forager *f){



    if(f->getEN2()== false){// hasnt gotten in any line

        boardVect.at(boardcycle).addToEnterLine(f);

        if(changenow>4){
            changenow =0;
            boardcycle++;
            if(boardcycle == boardVect.size()){
                boardcycle =0;


            }
        }
        changenow++;
        // go through first gate
    }
    else if(f->getEX2() == false){// made it to the front of the line and triggered the first gate
        // do nothing
    }
    else if (f->getEN1() == false) {// triggered second gate

        // go through second gates
    }
    else if(f->getEx1() == false){// in second gate
        // do nothing
    }
    else {
        BeeCounter++;
         BeeCounter2++;
        f->setEnter(false);
        f->setEN2(false);
        f->setEN1(false);
        f->setEX2(false);
        f->setEX1(false);
//cout<<"enter"<<endl;
        if(f->getDance()){
            f->setDanceB(true);
            f->setNest(false);

            f->setTime(0);
        }
        else{
            f->setEat(true);
            f->setNest(false);

            f->setTime(0);
        }
    }
}
void Beehive::exitStates(Forager *f){
    if(f->getEN1()== false){// hasnt gotten in any line
        boardVect.at(boardcycle).addToLine(f);
        if(changenow>4){
            changenow =0;
            boardcycle++;
            if(boardcycle == boardVect.size()){
                boardcycle =0;
            }
        }
                //cout<< "ex1"<<endl;
        changenow++;
        // go through first gate
    }
    else if(f->getEx1() == false){// made it to the front of the line and triggered the first gate
        // do nothing
        //cout<< "ex2"<<endl;
    }
    else if (f->getEN2() == false) {// triggered second gate
 //cout<< "ex3"<<endl;
        // go through second gates
    }
    else if(f->getEX2() == false){// in second gate
        // do nothing
        //cout<< "ex4"<<endl;
    }
    else {
        exitCounter++;
            exitCounter2++;
        f->setExit(false);
        f->setEN2(false);
        f->setEN1(false);
        f->setEX2(false);
        f->setEX1(false);
        f->setInit(true);
      //  cout<<"exit"<<endl;
   }
}
bool Beehive::hasTarget(Forager *f){


    if(f->getTarget()){
        f->setInit(false);
        f->setSearch(true);
        f->setTime(0);
        //cout<<"target"<<endl;
        return true;
    }
    else {
        f->setInit(false);
        f->setEX(true);
        f->setTime(0);
        //set state to exlpore
        //cout<<"no target"<<endl;
        return false;
    }
    // checks if the forager has a target(true)
    //or if it needs to search for a new flower(false)
}
bool Beehive::isTired(Forager *f){
    if(f->getTime() >= 1200+ randNumGen){// energy number is 100
        f->setEX(false);
        f->setSearch(false);
        f->setNest(true);
        //cout<<"tired"<<endl;
         randNumGen = (rand() % 10) + 1;
        return true;

    }
    else{
        return false;
    }
    //checks if the forager is tired while searching for food
}
bool Beehive::foundFood(Forager *f){
    isTired(f);

    if(f->getTarget() &&f->getTime() > 900+randNumGen){
        f->setEX(false);
        f->setSearch(false);
        f->setFoundFood(true);
        f->setFor(true);
        f->setTime(0);
         randNumGen = (rand() % 10) + 1;
        //cout<< "bee searching hive"<<endl;
        return true;
    }
    else if(f->getTime() > 1200+randNumGen){
        f->setEX(false);
        f->setSearch(false);
        f->setFoundFood(true);
        f->setTarget(true);
        f->setFor(true);
        f->setTime(0);
         randNumGen = (rand() % 10) + 1;
        //cout<< "bee exploring hive"<<endl;
        return true;
    }
    else {
        return false;
    }
    // checks if the bee found food in its search
    // find ratio if bee has a target
    // find ratio if bee does not have a target
}
void Beehive::Beehive::forageStep(Forager *f){
    if(f->getFull() == false){

    }
    else{
        f->setFor(false);
        f->setNest(true);
        f->setDance(dance(f));
        f->setTime(0);
     //cout<< "bee forage hive complete "<<endl;
        //set state to return to hive
    }
    if(f->getTime() >= 100+randNumGen){
        f->setFull(true);
        randNumGen = (rand() % 10) + 1;
    }
    f->setTime(f->getTime()+1);
    // begin collecting food
    //continue collecting food until full
}

void Beehive::SwarmTech(Bee *b){
    boardVect.at(boardcycle).addToLine(b);

    if(changenow>4){
        changenow =0;
        boardcycle++;
        if(boardcycle == boardVect.size()){
            boardcycle =0;
        }
    }
    changenow++;
    SWRMC++;
    SWRMC2++;
    // go through first gate
}
void Beehive::attackTech(Bee *b){
    boardVect.at(boardcycle).addToEnterLine(b);

    if(changenow>4){
        changenow =0;
        boardcycle++;
        if(boardcycle == boardVect.size()){
            boardcycle =0;
        }
    }
    atkC++;
    atkC2++;
    changenow++;
    // go through first gate
}

void Beehive::returnToNest(Forager *f){

    if(f->getTime() >= 600+randNumGen){
        f->setNest(false);
        f->setEnter(true);
         randNumGen = (rand() % 10) + 1;
        //cout<< "bee nesting hive"<<endl;
        return;
    }
    f->setTime(f->getTime()+1);
    // state for returning to the nest
}
void Beehive::explore(Forager *f){

    f->setTime(f->getTime()+1);

    foundFood(f);
    // state for exploring
}
void Beehive::searchForThing(Forager *f){
    f->setTime(f->getTime()+1);
    foundFood(f);
    // state for bee heading toward a known food location
}
bool Beehive::dance(Forager *f){
    if(f->getTarget()){
        return true;
    }
    else{
        return false;
    }

    // decide of bee will dance or not
    // find ratio
}
void Beehive::beginDance(Forager *f){
    for (int var = 0; var < forageVect.size(); ++var) {
        if(forageVect.at(var).getTarget() == false){
            forageVect.at(var).setTarget(true);
            f->setEat( true);
            f->setDance(false);
            f->setDanceB(false);
            f->setTime(0);
            return;
        }
    }
    f->setEat( true);
    f->setDance(false);
    f->setDanceB(false);
    f->setTime(0);
    //cout<<"Bdance"<<endl;
}
void Beehive::restOrEat(Forager *f){

    if(f->getTime() > 3600+randNumGen){
        f->setEat( false);
        f->setTime(0);
        f->setFull(true);
        f->setTired(false);
        //cout<< "bee eating hive"<<endl;
        f->setExit(true);
 randNumGen = (rand() % 10) + 1;
        f->setTime(0);
    }
    else {
        f->setTime(f->getTime()+1);
    }
    //sleep until rested
}
void Beehive::setCurrentTime(int x){
    currentTime = x;
}
int Beehive::getCurrentTime(){
    return currentTime;
}
vector<Board> Beehive::getBoards(){
    return boardVect;
}
vector<Bee> Beehive::getBees(){
    return beeVect;
}
vector<Drone> Beehive::getDrones(){
    return droneVect;
}
vector<Nurse*> Beehive::getNurses(){
    return nurseVect;
}
vector<Brood*> Beehive::getbroods(){
    return broodVect;
}
vector<Juvinile*> Beehive::getJuviniles(){
    return juviVect;
}
vector<Worker> Beehive::getWorkers(){
    return workerVect;
}
vector<Forager> Beehive::getForagers(){
    return forageVect;
}
void Beehive::setFood(double x){
    foodAmount = x;
}
double Beehive::getFood(){
    return foodAmount;
}
void Beehive::setPollen(double x){
    pollenAmmount = x;
}
double Beehive::getPollen(){
    return pollenAmmount;
}
string Beehive::parseTime(int t){
    string s;

    int year =2019+(t / 29030400);
    int temp = t % 29030400;
    int month = 1+(temp / 2419200);
    temp = temp % 2419200;
    int day = 1+(temp / 86400) ;

    int hour = (t % 86400)/3600 ;

    int minute = (t % 3600)/60;

    int second = t % 60;
    int mill = milliCounter;

    s.append("D");
    s.append(to_string(day));
    s.append(".");
    s.append(to_string(month));
    s.append(".");
    s.append(to_string(year));


    s.append("T");
    s.append(to_string(hour));
    s.append(".");
    s.append(to_string(minute));
    s.append(".");
    s.append(to_string(second));
    if(mill <10){
        string temp ="00";
        temp.append(to_string(mill));

        s.append(temp);
    }

    else if(mill<100){
        string temp ="0";
        temp.append(to_string(mill));

        s.append(temp);
    }
    else{
        s.append(to_string(mill));
    }
    return s;
}
string Beehive::boardString(){
    string s;
    s.append("-");
    for(int i=0;i<numOfBoards;i++){
        s.append("B");
          s.append(to_string(boardVect.at(i).calculateBool()));
    }
    ////cout<<"s - "<<s<<endl;
    return s;
}
void Beehive::run(){
    setup();

    for (int i=0;i<numofyears;i++) {
        OneWeekTimeStep();
        //OneYearTimeStep();
        //OneDayTimeStep();
        //OneHourTimeStep();
        // OneMonthTimeStep();
    }

    //  testFunction();
    //  checkbees();

}
void Beehive::testFunction(){
    //Board k;
    //  k.testFunct();


    //////cout<<k.calculateBool()<<endl;



}
