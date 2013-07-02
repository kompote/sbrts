static sf::Text localFPSText( "0 FPS", sf::Font::GetDefaultFont(), 15 );
static sf::Text localMemoryText( "0/0 Bytes", sf::Font::GetDefaultFont(), 15 );
static sf::Uint32 localFrameCounter = 0;
static sf::Uint32 localFrameTime = 0;
static sf::Uint32 localFPS = 0;


void GDI::Init()
{
    localFPSText.SetPosition( 5, 5 );
    localMemoryText.SetPosition( 5, 25 );

    localFPSText.SetColor( sf::Color::Yellow );
    localMemoryText.SetColor( sf::Color::Yellow );
}

void GDI::MemoryUsage( sf::Uint64 &someUsedMemory, sf::Uint64 &someAllocatedMemory )
{
    PROCESS_MEMORY_COUNTERS memoryData;
    assert( GetProcessMemoryInfo( GetCurrentProcess(), &memoryData, sizeof( memoryData ) ) == TRUE );

    someUsedMemory = memoryData.WorkingSetSize;
    someAllocatedMemory = memoryData.PagefileUsage;
}

void GDI::Update( const sf::Uint32 someTime )
{
    localFrameCounter += 1;
    localFrameTime += someTime;
    if( localFrameTime >= 1000 )
    {
        localFPS = localFrameCounter;
        localFrameCounter = 0;
        localFrameTime -= 1000;

        localFPSText.SetString( GDE::ConvertToString( localFPS ) + " FPS" );

        sf::Uint64 usedMemory = 0;
        sf::Uint64 allocatedMemory = 0;
        GDE::RuntimeDisplayer::MemoryUsage( usedMemory, allocatedMemory );

        localMemoryText.SetString( GDE::ConvertToString( static_cast< float >( usedMemory / 1024 ) / 1024.f ) + "/" + GDE::ConvertToString( static_cast< float >( allocatedMemory / 1024 ) / 1024.f ) + " Megabytes" );
    }
}

void GDI::Render( sf::RenderTarget &aTarget )
{
    sf::View oldView = aTarget.GetView();
    aTarget.SetView( aTarget.GetDefaultView() );
    aTarget.Draw( localFPSText );
    aTarget.Draw( localMemoryText );
    aTarget.SetView( oldView );
}
