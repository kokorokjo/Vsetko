
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
vector<double> sight{500, 600, 700, 800, 900, 1000, 1100, 1200};

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
    Command command;
    
   
   
    

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
    // if(player.health<100){
    //     world.entities.resize(0);
    // }
    if(world.entities.size()==0){
        a=0;
        b=0;

    }
    if(myself.position.x==0&&myself.position.y==0&&world.entities.size()==0&&world.players.size()==1){
       command.angle = 0.785398;
    nie==true;
    }
    if(asik&&myself.tankType==Tank::Peaceful){
        if(myself.position.x==(world.max_x+world.min_x)/2){
            if(myself.position.y==(world.max_y+world.min_y)/2){
                asik=false;
            }
        }
        a=0;
        b=0;

    }
    pocitanie=1;
    if(myself.tankType==Tank::Peaceful){
        if(world.players.size()>1){
        a=world.players[0+pocitanie].position.x;
        b=world.players[0+pocitanie].position.y;
        pocitanie++;

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
    }
    if(myself.position.x>world.max_x||myself.position.x<world.min_x||myself.position.y<world.min_y||myself.position.y>world.max_y){
        a=(world.max_x+world.min_x)/2;
        b=(world.max_y+world.min_y)/2;
    }
    
    if(!nie){
        std::complex<double> dir(a-myself.position.x,b-myself.position.y);
    command.angle = std::arg(dir);

    }
    

    command.new_position = {a-myself.position.x,b-myself.position.y};
    command.shoot = ShootType::OneBullet; 
    if(myself.tankType==Tank::Asymetric) command.new_tank_id=Tank::Peaceful;
    else command.new_tank_id=Tank::Asymetric;
    if(world.stat_levels[7]<4) command.stat=Stat::HealthRegeneration;
    else  if (world.stat_levels[8]<7) command.stat=Stat::BodyDamage;
    else if (world.stat_levels[2]<6) command.stat=Stat::Speed;
    else if (world.stat_levels[1]<7) command.stat=Stat::Range;
    else command.stat=Stat::HealthMax;

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

