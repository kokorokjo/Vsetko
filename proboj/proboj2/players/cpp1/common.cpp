#include "common.h"

//uplne nezaujimave nemusis citat
//definuje iba format komunikacie so serverom

std::ostream &operator<<(std::ostream &out, const ShootType &shoot) {
    out << static_cast<int>(shoot);
    return out;
}

std::ostream &operator<<(std::ostream &out, const Stat &stat) {
    out << static_cast<int>(stat);
    return out;
}

std::ostream &operator<<(std::ostream &out, const Tank &tank) {
    out << static_cast<int>(tank);
    return out;
}

std::ostream &operator<<(std::ostream &out, const Command &cmd) {
    out << cmd.new_position << ' ' << cmd.shoot << ' ';
    switch (cmd.shoot) {
        case ShootType::No:
            break;
        case ShootType::OneBullet:
            out << cmd.angle << ' ';
            break;
        case ShootType::TwoBullet:
            out << cmd.angle1 << ' ' << cmd.angle2 << ' ';
            break;
        case ShootType::Player:
            out << cmd.follow_player_id << ' ';
            break;
        case ShootType::Coordinates:
            out << cmd.follow_coordinates << ' ';
            break;
    }

    out << cmd.stat << ' ' << cmd.new_tank_id << "\n." << std::endl;
    return out;
}

int Player::_id = 0;

std::istream &operator>>(std::istream &in, Player &p) {
    int tankType;
    in >> p.id >> p.alive >> p.position >> p.angle >> p.radius >> tankType >> p.health;
    p.tankType = static_cast<Tank>(tankType);
    return in;
}

std::istream &operator>>(std::istream &in, Bullet &b) {
    in >> b.position >> b.velocity >> b.shooter_id >> b.ttl >> b.damage >> b.radius;
    return in;
}

std::istream &operator>>(std::istream &in, Entity &e) {
    in >> e.position >> e.radius >> e.health;
    return in;
}

std::istream &operator>>(std::istream &in, World &w) {
    in >> w.min_x >> w.max_x >> w.min_y >> w.max_y;

    in >> w.my_id >> w.exp >> w.level >> w.levels_left >> w.tank_updates_left >> w.reload_cooldown >> w.lifes_left;

    for (size_t i = 1; i < w.stat_levels.size(); i++) in >> w.stat_levels[i];
    for (size_t i = 1; i < w.stat_values.size(); i++) in >> w.stat_values[i];

    int player_count;
    in >> player_count;
    w.players.resize(player_count);
    for (int i = 0; i < player_count; i++) in >> w.players[i];

    int bullet_count;
    in >> bullet_count;
    w.bullets.resize(bullet_count);
    for (int i = 0; i < bullet_count; i++) in >> w.bullets[i];

    int entity_count;
    in >> entity_count;
    w.entities.resize(entity_count);
    for (int i = 0; i < entity_count; i++) in >> w.entities[i];


    char dot;
    in >> dot;
    return in;
}

