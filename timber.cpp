#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Timber!!");
    View view(FloatRect(0,0,1920,1000));
    window.setView(view);
    Texture textureBackground;
    textureBackground.loadFromFile("graphics/background.png");
    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);

    Texture textureTree;
    textureTree.loadFromFile("graphics/tree.png");
    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    Texture textureBee;
    textureBee.loadFromFile("graphics/bee.png");
    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(10, 200);
    bool beeActive=false;
    float beeSpeed=0.0f;


    // Texture textureCloud;
    // textureCloud.loadFromFile("graphics/cloud.png");
    // Sprite spriteCloud;
    // spriteCloud.setTexture(textureCloud);
    // spriteCloud.setPosition(0, 200);

    // float cloudSpeed=15;
    // float cloudSpeedPerSec=1920/cloudSpeed;
    
    Time dt;
    Clock clock;
    Font font;
    font.loadFromFile("KOMIKAP_.ttf");
    int score=0;
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10,10);
    scoreText.setString("Score: 0");
    float totalTime=10.0f;
    float elapsedTime=0.0f;
    float barWidth=600.0f;
    float barHeight=40.0f;
    RectangleShape timeBar;
    timeBar.setSize(sf::Vector2f(barWidth,barHeight));
    timeBar.setFillColor(sf::Color::Red);
    timeBar.setPosition(250,900);

    while(window.isOpen()) 
    {
        dt=clock.restart();
        Event event;
        while(window.pollEvent(event)) 
        {
            if(event.type == Event::Closed)
                window.close();
        }
        if(!beeActive)
        {
            srand((int)time(0));
            beeSpeed=(rand()%200)+200;
            srand((int)time(0)*10);
            float height=(rand()%500)+500;
            spriteBee.setPosition(2000,height);
            beeActive=true;
        }
        else
        {
            spriteBee.setPosition(spriteBee.getPosition().x-(beeSpeed*dt.asSeconds()),spriteBee.getPosition().y);
            if(spriteBee.getPosition().x<-100)
                beeActive=false;
        }
        // if(spriteCloud.getPosition().x>1920)
        //     spriteCloud.setPosition(0,200);
        // else
        //      spriteCloud.setPosition(spriteCloud.getPosition().x+(dt.asSeconds()*cloudSpeedPerSec),200);
        
        // if(spriteBee.getPosition().x<0)
        //     spriteBee.setPosition(1920,400);
        // else
        // {
        //     spriteBee.setPosition(spriteBee.getPosition().x-(dt.asSeconds()*200),400);
        //     if(spriteBee.getPosition().x<-100)
        //         beeActive=false;
            
        // score+=1;
        scoreText.setString("Score "+std::to_string(score));
        elapsedTime+=dt.asSeconds();
        float remainingRatio=((totalTime-elapsedTime)/totalTime);
        if(remainingRatio>0.0f)
            timeBar.setSize(sf::Vector2f(barWidth*remainingRatio,barHeight));
        else
            timeBar.setSize(sf::Vector2f(0,barHeight));
        window.clear();
        window.draw(spriteBackground);
        // window.draw(spriteCloud);
        window.draw(spriteTree);
        window.draw(spriteBee);
        window.draw(scoreText);
        window.draw(timeBar);
        window.display();
    }
    return 0;
}
