#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

namespace SSLib
{
    class UserInterface
    {
    public:
       virtual void Run()=0;
       virtual ~UserInterface() {};
    };
}

#endif
