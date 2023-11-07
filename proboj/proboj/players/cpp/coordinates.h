#ifndef CPP_COORDINATES
#define CPP_COORDINATES

struct Coordinates {
    long double x, y;

    auto operator<=>(const Coordinates &) const = default;

    Coordinates& operator+=(const Coordinates& rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
//
    friend Coordinates operator+(Coordinates &lhs, const Coordinates &rhs) {
        lhs += rhs;
        return lhs;
    }

    Coordinates& operator-=(const Coordinates& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    friend Coordinates operator-(Coordinates &lhs, const Coordinates &rhs) {
        lhs -= rhs;
        return lhs;
    }

    Coordinates& operator*=(long double rhs) {
        x *= rhs;
        y *= rhs;
        return *this;
    }

    friend Coordinates operator*(Coordinates &lhs, long double rhs) {
        lhs *= rhs;
        return lhs;
    }


    friend long double operator*(const Coordinates &lhs, const Coordinates &rhs) {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }

    friend long double squared_distance(Coordinates &lhs, const Coordinates &rhs) {
        lhs -= rhs;
        return lhs * lhs;
    }

    friend long double distance(Coordinates &lhs, const Coordinates &rhs) {
        return std::sqrt(squared_distance(lhs, rhs));
    }

    friend std::istream &operator>>(std::istream &in, Coordinates &rhs) {
        in >> rhs.x >> rhs.y;
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const Coordinates &rhs) {
        out << rhs.x << ' ' << rhs.y;
        return out;
    }
};

#endif //CPP_COORDINATES
