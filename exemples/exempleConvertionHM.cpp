class Base1
{
public:
    virtual void affiche() const {}
};
class Base2
{
};
class Derived : public Base1, public Base2
{
};

Base1 *b1 = new Derived();
Derived *d = dynamic_cast<Derived *>(b1); // conversion securisee

Derived *d = new Derived();
Base1 *b1 = d;                       // Conversion implicite
Base2 *b2 = static_cast<Base2 *>(d); // Conversion explicite