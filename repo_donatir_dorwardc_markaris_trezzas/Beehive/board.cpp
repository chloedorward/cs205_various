#include "board.h"

Board::Board()// issue where bee gets stuck in exiting, when it goes back into the hive when its not supposed to
{
    inner[0]= nullptr;
    inner[1]= nullptr;
    inner[2]= nullptr;
    inner[3]= nullptr;
    outer[1]= nullptr;
    outer[2]= nullptr;
    outer[3]= nullptr;
    outer[0]= nullptr;
    middle[0]= nullptr;
    middle[1]= nullptr;
    middle[2]= nullptr;
    middle[3]= nullptr;

    changedstates[0]=false;
    changedstates[2]=false;
    changedstates[1]=false;
    changedstates[3]=false;
    changedstates[4]=false;
    changedstates[5]=false;
    changedstates[6]=false;
    changedstates[7]=false;
}

int Board::calculateBool(){
    int x =0;
    if(inner[0] != nullptr&&changedstates[0]){x+=1;}
    if(inner[1] != nullptr&&changedstates[1]){x+=10;}
    if(inner[2] !=nullptr&&changedstates[2]){x+=100;}
    if(inner[3] !=nullptr&&changedstates[3]){x+=1000;}
    if(outer[3] !=nullptr&&changedstates[7]){x+=10000;}
    if(outer[2] !=nullptr&&changedstates[6]){x+=100000;}
    if(outer[1] !=nullptr&&changedstates[5]){x+=1000000;}
    if(outer[0] !=nullptr&&changedstates[4]){x+=10000000;}

    string s = to_string(x);
    int test = std::stoi(s, nullptr, 2);

    return test;
}



void Board::testFunct(){

    if(inner[0]!= nullptr||middle[0]!= nullptr||outer[0]!=nullptr){
        if(FrontBack){
            ////cout<<"enter"<<endl;
        }
        else{
            ////cout<<"exit"<<endl;
        }
       //cout<<inner[0]<<"----"<<middle[0]<<"----"<<outer[0]<<"   gate 1"<<endl;
    }
    if(inner[1]!= nullptr||middle[1]!= nullptr||outer[1]!=nullptr){
        //cout<<inner[1]<<"----"<<middle[1]<<"----"<<outer[1]<<"   gate 2"<<endl;
    }

    if(inner[2]!= nullptr||middle[2]!= nullptr||outer[2]!=nullptr){
       //cout<<inner[2]<<"----"<<middle[2]<<"----"<<outer[2]<<"   gate 3"<<endl;
    }

    if(inner[3]!= nullptr||middle[3]!= nullptr||outer[3]!=nullptr){
       //cout<<inner[3]<<"----"<<middle[3]<<"----"<<outer[3]<<"   gate 4"<<endl;
    }

    //////cout<<"line"<<line.size()<<" enterline"<<Enterline.size()<<endl;

}

void Board::swapping(){

    FrontBack = !FrontBack;

}

int Board::checkBoards(){
    int x =0;
    if(changedstates[0]==true){
        x++;
    }
    if(changedstates[1]==true){
        x++;
    }
    if(changedstates[2]==true){
        x++;
    }
    if(changedstates[3]==true){
        x++;
    }
    if(changedstates[4]==true){
        x++;
    }
    if(changedstates[5]==true){
        x++;
    }
    if(changedstates[6]==true){
        x++;
    }
    if(changedstates[7]==true){
        x++;
    }
    return x;

}

bool Board::checkFinI(){
    bool x = true;
    for (int var = 0; var < 4; ++var) {
        if(inner[var]!=nullptr){
            x=false;
        }
        if(outer[var]!=nullptr){
            x=false;
        }
        if(middle[var]!=nullptr){
            x=false;
        }
    }
    return x;
}


void Board::checkSwap(){
    int randNum = (rand() % 10) + 1;
    if(condition >=randNum &&checkFinI()){
        condition = 0;
        swapping();
    }
    if(condition >=(randNum-1)){
        enterNew = false;
        if(FrontBack){
            if(Enterline.size() == 0){
                enterNew = true;
            }

        }
        else if(!FrontBack) {
            if(line.size() ==0){
                enterNew=true;
            }
        }
    }
    else {
        enterNew = true;
    }
}



void Board::updateline(int x){




    //////cout<<"line - "<<line.size()<<" enterline -"<<Enterline.size()<<endl;

    //testFunct();

    reset();

    if(((FrontBack)||(line.size()!=0&&Enterline.size()==0))&&(x>=21600&&x<=72000)){
        //<<line.size()<<" "<<Enterline.size()<<endl;
if(line.size()!=0&&Enterline.size()==0){
FrontBack = true;
}
        Traverse();

        condition++;


    }
    else{

        Inverse();

        condition++;
    }


    checkSwap();

}

void Board::reset(){
    for(int i=0;i<8;i++){
        changedstates[i]=false;
    }

}
void Board::Traverse(){
testFunct();

    Iterate();

testFunct();


    for (int i=0;i<4;i++) {


        if((enterNew)&&line.size()!=0){
            if(inner[gateCycle]!=nullptr){
                //////cout<<"things"<<endl;
            }
            inner[gateCycle]=line.at(0);
           //cout<<"bee exiting & gate "<<gateCycle<<endl;

            inner[gateCycle]->setEN1(true);
            line.erase(line.begin());
            changedstates[gateCycle] = true;

            gateCycle++;
            if(gateCycle>=4){
                gateCycle=0;
            }
        }
    }


}
void Board::Inverse(){

    InverseIterate();

    for (int i=0;i<4;i++) {
        if((enterNew )&&Enterline.size()!=0){
            //do the first transition
            if(outer[gateCycle]!=nullptr){
                ////cout<<"things"<<endl;
            }
            outer[gateCycle]=Enterline.at(0);

            outer[gateCycle]->setEN2(true);
            ////cout<<"EN2I"<<endl;
            Enterline.erase(Enterline.begin());
            changedstates[gateCycle+4] = true;


            //cout<<"bee entering & gate "<<gateCycle<<endl;

            gateCycle++;
            if(gateCycle>=4){
                gateCycle=0;
            }
        }
    }
}
void Board::Iterate(){


    if(outer[0]!=nullptr){
        outer[0]->setEX2(true);
        changedstates[4] = true;
        outer[0]=nullptr;
        //cout<<"Ex2T"<<endl;
        //output udp


    }

    //////cout<<"---------post first-----------"<<endl;
    if(outer[1]!=nullptr){
        outer[1]->setEX2(true);
        changedstates[5] = true;
        outer[1]=nullptr;
        //output udp
        //cout<<"Ex2T"<<endl;


    }

    //////cout<<"---------post second----------"<<endl;
    if(outer[2]!=nullptr){
        outer[2]->setEX2(true);
        changedstates[6] = true;
        outer[2]=nullptr;
        //output udp
        //cout<<"Ex2T"<<endl;
    }

    //////cout<<"---------post third-----------"<<endl;
    if(outer[3]!=nullptr){
        outer[3]->setEX2(true);
        changedstates[7]= true;
        outer[3]=nullptr;
        //output udp
        //cout<<"Ex2T"<<endl;
    }

    //////cout<<"---------post fourth-----------"<<endl;
    if(inner[0]!=nullptr){
        middle[0] = inner[0];
        changedstates[0] = true;
        inner[0]->setEX1(true);
        inner[0]=nullptr;
        //output udp

        //cout<<"Ex1T"<<endl;
    }

    //////cout<<"---------post fifth-----------"<<endl;
    if(inner[1]!=nullptr){

        middle[1] = inner[1];
        changedstates[1] = true;
        inner[1]->setEX1(true);
        inner[1]=nullptr;
        //output udp
        //cout<<"Ex1T"<<endl;
    }

    //////cout<<"---------post sixth-----------"<<endl;
    if(inner[2]!=nullptr){

        middle[2] = inner[2];
        changedstates[2] = true;
        inner[2]->setEX1(true);
        inner[2]=nullptr;
        //output udp
        //cout<<"Ex1T"<<endl;
    }
    //////cout<<"---------post seventh-----------"<<endl;
    if(inner[3]!=nullptr){

        middle[3] = inner[3];
        changedstates[3] = true;
        inner[3]->setEX1(true);
        inner[3]=nullptr;
        ////cout<<"Ex1T"<<endl;    //output udp
    }
    //////cout<<"---------post eighth----------"<<endl;
    if(middle[0]!=nullptr){
        middle[0]->setEN2(true);
        changedstates[4] = true;
        outer[0] = middle[0];
        middle[0]=nullptr;
        //output udp
        //cout<<"En2T"<<endl;
    }
    //////cout<<"---------post ninth-----------"<<endl;
    if(middle[1]!=nullptr){
        middle[1]->setEN2(true);
        changedstates[5] = true;
        outer[1] = middle[1];
        middle[1]=nullptr;
        //output udp
        //cout<<"En2T"<<endl;
    }
    //////cout<<"---------post tenth-----------"<<endl;
    if(middle[2]!=nullptr){
        middle[2]->setEN2(true);
        changedstates[6] = true;
        outer[2] = middle[2];
        middle[2]=nullptr;
        //output udp
        //cout<<"En2T"<<endl;
    }

    //////cout<<"---------post eleventh-----------"<<endl;
    if(middle[3]!=nullptr){
        middle[3]->setEN2(true);
        changedstates[7] = true;
        outer[3] = middle[3];
        middle[3]=nullptr;
        //output udp
        //cout<<"En2T"<<endl;
    }



}
void Board::InverseIterate(){
    // do second-fourth iteration
    ////////cout<<" problem here"<<endl;

    if(inner[0]!=nullptr){
        changedstates[0] = true;
        inner[0]->setEX1(true);
        inner[0]=nullptr;
        //output udp
        //cout<<"Ex1I"<<endl;

    }
    ////////cout<<"1"<<endl;
    if(inner[1]!=nullptr){

        changedstates[1] = true;
        inner[1]->setEX1(true);
        inner[1]=nullptr;
        //output udp
        //cout<<"Ex1I"<<endl;
    }
    ////////cout<<"2"<<endl;
    if(inner[2]!=nullptr){
        changedstates[2] = true;
        inner[2]->setEX1(true);
        inner[2]=nullptr;
        //output udp
        //cout<<"Ex1I"<<endl;
    }
    ////////cout<<"3"<<endl;
    if(inner[3]!=nullptr){
        changedstates[3] = true;
        inner[3]->setEX1(true);
        inner[3]=nullptr;
        //output udp
        //cout<<"Ex1I"<<endl;
    }

    ////////cout<<"4"<<endl;





    ////////cout<<"7"<<endl;



    if(outer[0]!=nullptr){
        changedstates[4] = true;
        middle[0] = outer[0];
        outer[0]->setEX2(true);
        outer[0]=nullptr;
        //output udp

        //cout<<"Ex2I"<<endl;
    }
    ////////cout<<"8"<<endl;
    if(outer[1]!=nullptr){
        middle[1] = outer[1];
        changedstates[5] = true;
        outer[1]->setEX2(true);
        outer[1]=nullptr;
        //output udp
        //cout<<"Ex2I"<<endl;

    }
    ////////cout<<"9"<<endl;
    if(outer[2]!=nullptr){
        changedstates[6] = true;
        middle[2] = outer[2];
        outer[2]->setEX2(true);
        outer[2]=nullptr;
        //output udp
        //cout<<"Ex2I"<<endl;
    }
    ////////cout<<"0"<<endl;
    if(outer[3]!=nullptr){
        changedstates[7] = true;
        middle[3] = outer[3];
        outer[3]->setEX2(true);
        outer[3]=nullptr;
        //output udp

        //cout<<"Ex2I"<<endl;
    }
    if(middle[0]!=nullptr){

        changedstates[0] = true;
        inner[0] = middle[0];
        middle[0]->setEN1(true);
        middle[0]=nullptr;
        //output udp
        //cout<<"En1I"<<endl;

    }
    ////////cout<<"5"<<endl;
    if(middle[1]!=nullptr){
        changedstates[1] = true;

        inner[1] = middle[1];
        middle[1]->setEN1(true);
        middle[1]=nullptr;
        //output udp
        //cout<<"En1I"<<endl;
    }

    if(middle[2]!=nullptr){
        changedstates[2] = true;

        inner[2] = middle[2];
        middle[2]->setEN1(true);
        middle[2]=nullptr;
        //output udp
        //cout<<"En1I"<<endl;
    }
    ////////cout<<"6"<<endl;
    if(middle[3]!=nullptr){
        changedstates[3] = true;
        inner[3] = middle[3];
        middle[3]->setEN1(true);
        middle[3]=nullptr;
        //output udp
        //cout<<"En1I"<<endl;
    }


    //////////cout<<"  here the end"<<endl;

}
void Board::addToLine(Bee *b){
    line.push_back(b);
}
void Board::addToEnterLine(Bee *b){
    Enterline.push_back(b);
}
