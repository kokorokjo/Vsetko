#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>
#include <iterator>
#include <sstream>
#include <cmath>
#include "coordinates.h"

enum class Stat : int {
    None,
    Range,
    Speed,
    BulletSpeed,
    BulletTTL,
    BulletDamage,
    HealthMax,
    HealthRegeneration,
    BodyDamage,
    ReloadSpeed,
};

enum class Tank : int {
    Basic,
    Twin,
    Everywhere,
    VariableDouble,
    DoubleDouble,
    Sniper,
    WideBullet,
    GuidedBullet,
    MachineGun,
    Asymetric,
    Peaceful,
    InvisibleBullet,
    AsymetricTriple,
};

enum class ShootType : int {
    No,
    OneBullet,
    TwoBullet,
    Player,
    Coordinates,
};

struct Bullet {
    Coordinates position;
    Coordinates velocity;
    int shooter_id;
    long double ttl;
    long double damage;
    long double radius;
};

struct Entity {
    Coordinates position;
    long double radius;
    long double health;
};

struct Player {
    int id;
    bool alive = false;
    Coordinates position;
    long double angle = 0;
    long double radius = 0;
    long double health = 0;
    Tank tankType = Tank::Basic;
    std::vector<Tank> updatable_to {Tank::Twin, Tank::Sniper, Tank::Asymetric};
    std::vector<long double> tank_stats {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    Player() {
        id = _id++;
    }

    friend std::istream &operator>>(std::istream &in, Player &p);

    friend std::ostream &operator<<(std::ostream &out, const Player &p);

private:
    static int _id;
};


struct World {
    long double min_x;
    long double max_x;
    long double min_y;
    long double max_y;
    int my_id = 0;
    int exp = 0;
    int level = 0;
    int levels_left = 0;
    int tank_updates_left = 0;
    int reload_cooldown = 0;
    int lifes_left = 3;
    std::vector <int> stat_levels  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector <long double> stat_values  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<Player> players;
    std::vector<Bullet> bullets;
    std::vector<Entity> entities;

    friend std::istream &operator>>(std::istream &in, World &w);

    friend std::ostream &operator<<(std::ostream &out, const World &w);
};


struct Command {
    Coordinates new_position;
    ShootType shoot = ShootType::No;
    Stat stat = Stat::None;
    Tank new_tank_id = Tank::Basic;

    //shoot type arguments
    int follow_player_id = 0;
    Coordinates follow_coordinates;
    long double angle = 0;
    long double angle1 = 0;
    long double angle2 = 0;
};

/**
* Print any vector to output
* @tparam T type inside vector
* @param out stream to which output will we written
* @param v input vector
* @return out stream
*/
namespace std {
    template<class T>
    ostream &operator<<(ostream &out, const vector<T> &v) {
        ranges::copy(v, ostream_iterator<T>(out, " "));
        out << '\n';
        return out;
    }
}

std::ostream &operator<<(std::ostream &out, const ShootType &shoot);

std::ostream &operator<<(std::ostream &out, const Stat &stat);

std::ostream &operator<<(std::ostream &out, const Command &cmd);


#endif
