
#include <complex>
#include <algorithm>
#include "common.h"


using namespace std;

#define NAME "cpp"
#define COLOR "00ff00"

World world;
Player player;
long double a=0,b=0;
bool asi = false;
Player myself;
bool asik=true;
bool nie=false;
Command command;
Coordinates coordinates;
bool skip=false,ad=false;
bool xx,yy;
bool jeden=false,dva=false,tri=false,styri=false;

template<class T>
bool cmp_entity (const T &a, const T &b){
    return abs(std::complex<long double>{a.position.x-myself.position.x,a.position.y-myself.position.y}) < abs(std::complex<long double>{b.position.x-myself.position.x,b.position.y-myself.position.y}) ;
}

Command do_turn() {
 
    int my_real_id;
    for(int i=0;i<world.players.size();i++){
        if(world.players[i].id == world.my_id) {
            my_real_id = i;
            break;
        } 
    }
    myself = world.players[my_real_id];
    world.my_id = my_real_id;
    
    
    sort(world.entities.begin(),world.entities.end(), cmp_entity<Entity>);
    sort(world.players.begin(),world.players.end(), cmp_entity<Player>);
    
    a=world.entities[0].position.x;
    b=world.entities[0].position.y;
    int pocitanie=1;
    while(a>world.max_x||a<world.min_x||b<world.min_y||b>world.max_y){
        a=world.entities[0+pocitanie].position.x;
        b=world.entities[0+pocitanie].position.y;
        pocitanie++;
        if(pocitanie == world.entities.size()){
            world.entities.resize(0);
            break;
        }
    }
    
    
    
    if(world.entities.size()==0){
        for(int i=1;i<world.players.size();i++){
            if(world.players[i].tankType==Tank::Basic||world.players[i].health<=world.stat_values[8]){
                a=world.players[i].position.x;
                b=world.players[i].position.y;
                skip=true;
                break;

            }
        }
        if(!skip){
            //potahovat po borderi
        a=0;
        b=0;
            if(myself.position.x>0){
                a=world.max_x-500;
                xx=false;
            }
            else{
                a=world.min_x+500;
                xx=true;
            }
            if(myself.position.y>0){
                b=world.max_y-500;
                yy=false;
            }
            else{
                b=world.min_y+500;
                yy=true;
            }
        
        }
        skip=false;
        if(myself.position.x==world.max_x-500&&myself.position.y==world.max_y-500||jeden){
            jeden = true;
            a=world.max_x-500;
            b=world.min_y+500;
            if(myself.position.y==world.min_y+500) jeden=false;
        }
        
        if(myself.position.x==world.max_x-500&&myself.position.y==world.min_y+500||dva){
            dva=true;
            a=world.min_x+500;
            b=world.min_y+500;
                        if(myself.position.x==world.min_y+500) dva=false;

        }
        if(myself.position.x==world.min_x+500&&myself.position.y==world.min_y+500||tri){
            tri=true;
            a=world.min_x+500;
            b=world.max_y-500;
                        if(myself.position.y==world.max_y-500) tri=false;

        }
        if(myself.position.x==world.min_x+500&&myself.position.y==world.max_y-500||styri){
            styri=true;
            a=world.max_x-500;
            b=world.max_y-500;
                        if(myself.position.x==world.max_x-500) styri=false;

            
        }

    }





    if(asik&&myself.tankType==Tank::Peaceful){
        if(myself.position.x<5&&myself.position.x>-5){{}
            if(myself.position.y<5&&myself.position.y>-5){
                asik=false;
            }
        }
        a=0;
        b=0;

    }

    //dodge bulet
    if(myself.health<=world.stat_values[6]/2){
        if(ad){
            ad=false;
        a=myself.position.x+200;
        b=myself.position.y+200;
        }
        else{
            a=myself.position.x-200;
        b=myself.position.y-200;
        ad=true;
        }
        
    }




    pocitanie=1;
    if(myself.tankType==Tank::Peaceful){
        if(world.players.size()>1){
        a=world.players[0+pocitanie].position.x;
        b=world.players[0+pocitanie].position.y;
        pocitanie++;
        for(int i=1;i<world.players.size();i++){
            if(world.players[i].tankType==Tank::Basic){
                a=world.players[i].position.x;
                b=world.players[i].position.y;
                skip=true;
                break;

            }
        }

        if(skip==false){

            while(a>world.max_x||a<world.min_x||b<world.min_y||b>world.max_y){
        a=world.players[0+pocitanie].position.x;
        b=world.players[0+pocitanie].position.y;
        pocitanie++;
        if(pocitanie == world.players.size()){
            world.players.resize(0);
            break;
        }
            }
    }
    skip=true;
}
}


    if(myself.position.x>world.max_x||myself.position.x<world.min_x||myself.position.y<world.min_y||myself.position.y>world.max_y){
        a=0;
        b=0;
    }
    
   
    std::complex<double> dir(a-myself.position.x,b-myself.position.y);
    command.angle = std::arg(dir);

    
    

    command.new_position = {a-myself.position.x,b-myself.position.y};
    command.shoot = ShootType::OneBullet; 
    if(myself.tankType==Tank::Asymetric) command.new_tank_id=Tank::Peaceful;
    else command.new_tank_id=Tank::Asymetric;
    if(world.stat_levels[7]<5) command.stat=Stat::HealthRegeneration;
    else if(world.stat_levels[6]<3) command.stat=Stat::HealthMax;
    else if(world.stat_levels[8]<7) command.stat=Stat::BodyDamage;
    else if(world.stat_levels[2]<3) command.stat=Stat::Speed;
    else if(world.stat_levels[1]<3) command.stat=Stat::Range;
    else if(world.stat_levels[2]<7) command.stat=Stat::Speed;
    else if(world.stat_levels[6]<7) command.stat=Stat::HealthMax;
    else command.stat=Stat::HealthRegeneration;
    cerr << command << '\n';

    return command;
}

int main() {


    
    srand(time(nullptr));
    // robime tahy kym sme zivy
    do {
        cin >> world;
        cout << do_turn();
    } while (true);
    //cout << "Bye\n";
}

