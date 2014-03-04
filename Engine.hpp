#ifndef ENGINE_HPP
#define ENGINE_HPP

class Engine
{
    public:
        Engine();
        virtual ~Engine();
        virtual void setup()=0;
        virtual void update(float elapsedTime)=0;
};

#endif // ENGINE_HPP
