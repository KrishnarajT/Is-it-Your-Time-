#include"Header.h"
sf::RectangleShape Min_Hand ( sf::Vector2f ( 200.0f, 10.0f ) );
sf::RectangleShape Hr_Hand ( sf::Vector2f ( 120.0f, 10.0f ) );	
sf::RectangleShape Bar ( sf::Vector2f (1.0f, 25.0f) );

class General
{
	public:
	sf::Text Est_Time, Rel_Time, Timer_Text, Match_Text;
	sf::Texture Menu_Tex;
	sf::Texture Main_Tex;
	sf::Sprite Main_Background;
	sf::Sprite Menu_Background;

}Gen_Obj;
	int Estimated_Time, Real_Time;
class Main_Menu_Screen : public General
{
	public:
	int Responsibility_of_Menu;
	int Key_Press_Checker ()
	{
		if( sf::Keyboard::isKeyPressed ( sf::Keyboard::P ) )
		{
			return 1;
		}
		else if( sf::Keyboard::isKeyPressed ( sf::Keyboard::Q ) )
		{
			return 2;
		}
		else return 0;
	}
	int Main ()
	{
		sf::CircleShape Clock;
		sf::Clock Timer;
		sf::Time T1;
		Menu_Tex.loadFromFile ( "Resources/Backgrounds/Menu.jpg" );
		Menu_Background.setTexture ( Menu_Tex );
		sf::RenderWindow window ( sf::VideoMode ( 1536, 864 ), "HANG MAN", sf::Style::Close | sf::Style::Resize );
		while( window.isOpen () )
		{
			sf::Event evnt;
			while( window.pollEvent ( evnt ) )
			{
				switch( evnt.type )
				{
					case sf::Event::Closed:
						window.close ();
						break;
				}
			}
			window.clear ( sf::Color::White );
			window.draw ( Menu_Background );
			window.display ();
			Responsibility_of_Menu = Key_Press_Checker ();
			if( Responsibility_of_Menu != 0 )
				return Responsibility_of_Menu;
		}
		_getch ();
	}
}Obj_Menu;
class Main_Screen : public General
{
	public:
	int Minute_Ran;
	int Hour_Ran;
	string Estimated_Time_Str = "", Estimated_Time_Str_Conv = "";
	int Min_Rotation, Hr_Rotation;
	int extra = 0;
	int Pos_X_Min_Hand, Pos_Y_Min_Hand;
	int Pos_X_Hr_Hand, Pos_Y_Hr_Hand;
	string Real_Time_Str;
	sf::Font Time_Font;
	int Pos_X_Clock_Hands [ 60 ] = { 0, -45, -83, -116, -142, -162, -176, -181, -182, -176, -160, -141, -113 ,-81 ,-43 , 4, 51, 103, 162, 222, 284, 349, 413, 479, 545, 609, 671, 731, 787, 841, 889, 933, 973, 1005, 1033, 1053, 1065, 1071, 1071, 1065, 1051, 1029, 1003, 969, 931, 889, 839, 787, 729, 669, 609, 542, 476, 410, 346, 281, 219, 158, 101, 49 };


	int Pos_Y_Clock_Hands [ 60 ] = { 888, 840, 785, 730, 669, 607, 543, 477, 412, 347, 281, 219, 160, 103, 49, -1, -44, -82, -115, -141, -161, -176, -182, -184, -176, -160, -142, -114, -82, -44, 2, 50, 104, 160, 220, 282, 348, 416, 480, 545, 609, 673, 731, 789, 841, 891, 933, 973, 1005, 1031, 1053, 1065, 1071, 1071, 1065, 1051, 1032, 1004, 970, 933 };


	int Deg_Eq_of_Hr [ 12 ] = {0, 30, 60, 90, 120, 150, 180, 210, 240, 270, 300, 330};
	void randomiser ()
	{
		srand ( time ( 0 ) );
		Minute_Ran = rand () % 60;
		Hour_Ran = rand () % 12;
		Pos_X_Min_Hand = Pos_X_Clock_Hands [ Minute_Ran ];
		Pos_Y_Min_Hand = Pos_Y_Clock_Hands [ Minute_Ran ];
		if( Minute_Ran == 0 )
		{
			Pos_X_Hr_Hand = Pos_X_Clock_Hands [ Hour_Ran * 5 ];
			Pos_Y_Hr_Hand = Pos_Y_Clock_Hands [ Hour_Ran * 5 ];
			extra = 0;
		}
		else if( Minute_Ran <= 15 )
		{
			Pos_X_Hr_Hand = Pos_X_Clock_Hands [ ( Hour_Ran * 5 ) + 1 ];
			Pos_Y_Hr_Hand = Pos_Y_Clock_Hands [ ( Hour_Ran * 5 ) + 1 ];
			extra = 1;
		}
		else if( Minute_Ran <= 30 )
		{
			Pos_X_Hr_Hand = Pos_X_Clock_Hands [ ( Hour_Ran * 5 ) + 2 ];
			Pos_Y_Hr_Hand = Pos_Y_Clock_Hands [ ( Hour_Ran * 5 ) + 2 ];
			extra = 2;
		}
		else if( Minute_Ran <= 45 )
		{
			Pos_X_Hr_Hand = Pos_X_Clock_Hands [ ( Hour_Ran * 5 ) + 3 ];
			Pos_Y_Hr_Hand = Pos_Y_Clock_Hands [ ( Hour_Ran * 5 ) + 3 ];
			extra = 3;
		}
		else if( Minute_Ran <= 59 )
		{
			Pos_X_Hr_Hand = Pos_X_Clock_Hands [ ( Hour_Ran * 5 ) + 4 ];
			Pos_Y_Hr_Hand = Pos_Y_Clock_Hands [ ( Hour_Ran * 5 ) + 4 ];
			extra = 4;
		}
		if( Minute_Ran > 15 )
		{
			Min_Rotation = ( Minute_Ran * 6 ) - 90; // this is the angle in degres for the minute hand
			Hr_Rotation = (6 * ( Hour_Ran * 5 ) + ( 6 * extra )) - 90; // also the angle in degrees for the hour hand
		}
		else if( Minute_Ran < 15 )
		{
			Min_Rotation = ( Minute_Ran * 6 ) +270; // this is the angle in degres for the minute hand
			Hr_Rotation = (6 * ( Hour_Ran * 5 ) + ( 6 * extra )) + 270; // also the angle in degrees for the hour hand
		}
		Min_Hand.setPosition ( Pos_X_Min_Hand, Pos_Y_Min_Hand );
		Min_Hand.setRotation ( Min_Rotation );
		Hr_Hand.setPosition (Pos_X_Hr_Hand, Pos_Y_Hr_Hand );
		Hr_Hand.setRotation ( Hr_Rotation );
		if( Hour_Ran == 0 )
			Hour_Ran = 12;
		cout << "the random number for the minute hand is " << Minute_Ran;
		cout << endl;
		cout << "the random number for the hour hand is " << Hour_Ran;
		cout << endl;
		Real_Time = 100 * Hour_Ran + Minute_Ran;
		Real_Time_Str = to_string ( Hour_Ran ) + "    ";
		Real_Time_Str += to_string ( Minute_Ran );
		Rel_Time.setString ( Real_Time_Str );
	}
	void Set_Attributes ()
	{

		Time_Font.loadFromFile ( "Resources/Fonts/Game Fonts/trench.ttf" );
		Main_Tex.loadFromFile ( "Resources/Backgrounds/Main.jpg" );
		Est_Time.setFont ( Time_Font );
		Est_Time.setOrigin ( -1050, -150 );// this is the origin that fits perfectly in the expected time slot

		Est_Time.setCharacterSize ( 150 );
		Est_Time.setFillColor ( sf::Color::Cyan );
		Est_Time.setStyle ( sf::Text::Style::Bold );

		Min_Hand.setFillColor ( sf::Color::Cyan );
		Min_Hand.setOrigin ( -440, -440 );
		Hr_Hand.setFillColor ( sf::Color::Cyan );
		Hr_Hand.setOrigin ( -440, -440 );

		Rel_Time.setFont ( Time_Font );
		Rel_Time.setCharacterSize ( 150 );
		Rel_Time.setFillColor ( sf::Color::Cyan );
		Rel_Time.setStyle ( sf::Text::Style::Bold );
		Rel_Time.setOrigin ( -1050, -600 );// this is the origin that fits perfectly in the real time slot
		Timer_Text.setFont ( Time_Font );
		Timer_Text.setCharacterSize ( 200 );
		Timer_Text.setFillColor ( sf::Color::Green );
		Timer_Text.setStyle ( sf::Text::Style::Bold );
		Timer_Text.setOrigin ( -100, -600 );
		Main_Background.setTexture ( Main_Tex );
	}

	void Main ()
	{
		Estimated_Time_Str = "";
		Estimated_Time_Str_Conv = "";
		sf::CircleShape Clock;
		sf::Clock Timer;
		sf::Time T1;
		int Number;
		Clock.setOrigin ( -425, -425);
		Clock.setRadius ( 15 );
		Clock.setFillColor ( sf::Color::White );
		sf::RenderWindow window ( sf::VideoMode ( 1536, 864 ), "HANG MAN", sf::Style::Close | sf::Style::Resize );
		Set_Attributes ();
		randomiser ();
		Timer.restart ();
		while( window.isOpen () )
		{
			sf::Event evnt;
			while( window.pollEvent ( evnt ) )
			{
				switch( evnt.type )
				{
					case sf::Event::Closed:
						window.close ();
						break;
					case sf::Event::TextEntered:
						if( evnt.text.unicode >= 48 && evnt.text.unicode <= 57 )
						{
							Estimated_Time_Str += char ( evnt.text.unicode );
							Estimated_Time_Str_Conv += char ( evnt.text.unicode );
						}
						break;
				}
			}
			T1 = Timer.getElapsedTime ();
			Est_Time.setString ( Estimated_Time_Str);
			if( float(Real_Time) / 1000.0 >= 1.0 )
			{
				if( Estimated_Time_Str.length () == 2 )
				{
					Estimated_Time_Str += "   ";
				}
			}
			else 
				if( Estimated_Time_Str.length () == 1 )
				{
					Estimated_Time_Str += "   ";
				}
			if( sf::Keyboard::isKeyPressed ( sf::Keyboard::Return ) || ( T1.asSeconds () >= 10 ) )
			{
				stringstream s ( Estimated_Time_Str_Conv );
				s >> Estimated_Time;
			}
			Timer_Text.setString ( to_string ( int (11 - T1.asSeconds () )) );
			window.clear ( sf::Color::White );
			window.draw ( Main_Background );
			if( T1.asSeconds () >= 10 )
			{
				window.draw ( Rel_Time );
			}
			window.draw ( Est_Time );
			window.draw ( Timer_Text );
			window.draw ( Min_Hand );
			window.draw ( Hr_Hand );
			window.draw ( Clock );
			window.display ();
			if( T1.asSeconds () >= 12 )
			{
				break;
			}
		}
		window.close ();
	}
}Obj_Main;
class Match_Screen : public General
{
	public:
	int Responsibility_Of_Match_Screen;
	sf::Font Time_Font;
	float Accuracy;
	int Key_Press_Checker ()
	{
		if( sf::Keyboard::isKeyPressed ( sf::Keyboard::A ) || sf::Keyboard::isKeyPressed ( sf::Keyboard::Return ) )
		{
			return 1;
		}
		else if( sf::Keyboard::isKeyPressed ( sf::Keyboard::Q ) )
		{
			return 2;
		}
		else return 0;
	}
	float Accuracy_Checker ()
	{
		//real time and the estimated time is in weird numbers like 1030 to convert it into minutes, we have to split them
		int Est_Hour, Est_Minute;
		Est_Minute = Estimated_Time % 100;
		Est_Hour = ( Estimated_Time - Est_Minute ) / 100;
		
		int Real_Hour, Real_Minute;
		Real_Minute = Real_Time % 100;
		Real_Hour = ( Real_Time - Real_Minute ) / 100;

		int Total_Est_Minutes, Total_Real_Minutes;
		Total_Est_Minutes = 60 * Est_Hour + Est_Minute;
		Total_Real_Minutes = 60 * Real_Hour + Real_Minute;
		
		int Difference;
		Difference = abs ( Total_Est_Minutes - Total_Real_Minutes );
		Accuracy = ( ( float ( Total_Real_Minutes - Difference ) ) / float ( Total_Real_Minutes ) ) * 100;
		return Accuracy;
	}
	void Set_Attributes ()
	{
		Time_Font.loadFromFile ( "Resources/Fonts/Game Fonts/trench.ttf" );
		Main_Tex.loadFromFile ( "Resources/Backgrounds/Match1.png" );		
		Main_Background.setTexture ( Main_Tex );
		Match_Text.setString ( to_string ( int ( Accuracy ) ) + " % " );
		Match_Text.setFont ( Time_Font );
		Match_Text.setCharacterSize ( 200 );
		Match_Text.setFillColor ( sf::Color::Green );
		Match_Text.setStyle ( sf::Text::Style::Bold );
		Match_Text.setOrigin ( -1000, -450 );// this is the origin that fits perfectly in the real time slot
	}

	int Main ()
	{	
		sf::RenderWindow window ( sf::VideoMode ( 1536, 864 ), "HANG MAN", sf::Style::Close | sf::Style::Resize );
		cout << Accuracy_Checker ();
		Set_Attributes ();
		Bar.setFillColor ( sf::Color::Green );
		Bar.setOrigin ( -802, -354 );
		Bar.setPosition ( 0.0f, 0.0f );
		while( window.isOpen () )
		{
			sf::Event evnt;
			while( window.pollEvent ( evnt ) )
			{
				switch( evnt.type )
				{
					case sf::Event::Closed:
						window.close ();
						break;
				}
			}
			if( Bar.getPosition ().x <= ( ( Accuracy * 673 ) / 100 ) )
			Bar.move ( sf::Vector2f (0.5f , 0.0f) );
			window.draw ( Main_Background );
			window.draw ( Match_Text );
			window.draw ( Bar );
			window.display ();
			Responsibility_Of_Match_Screen = Key_Press_Checker ();
			if( Responsibility_Of_Match_Screen != 0 )
				return Responsibility_Of_Match_Screen;
		}
		window.close ();
		_getch ();
		return 0;
	}
}Obj_Match;
int main ()
{
	int quit = 0, a, b;
	a = Obj_Menu.Main ();
	Delay ( 2000 );
	while( quit == 0 )
	{
		switch( a )
		{
			case 1:
				Obj_Main.Main();
				b = Obj_Match.Main ();
				if( b == 2 )
					quit = 1;
				else quit = 0;
				break;
			case 2:
				quit = 1;
				break;
		}
	}
	cout << "Thanks for Spending Time in - IS IT YOUR TIME";
	_getch ();
	return 0;
}