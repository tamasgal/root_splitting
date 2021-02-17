#include "TObject.h"

class TWhatever : 
    public TObject
{
    protected:
        double  a;
        int  b;

    public:
        TWhatever(): a(0), b(0){}
        virtual ~TWhatever() { }
        void SetA(const double a) { this->a = a; }
        void SetB(const int b) { this->b = b; }

    ClassDef(TWhatever, 5)
};
