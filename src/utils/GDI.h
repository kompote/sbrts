#include <SFML/Graphics.hpp>


class GDI
{
    public:
        GDI();
        ~GDI();

        void MemoryUsage( sf::Uint64 &someUsedMemory, sf::Uint64 &someAllocatedMemory );

        void Update( const sf::Uint32 someTime );
        void Init();
        void Render( sf::RenderTarget &aTarget );
};
