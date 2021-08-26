#include <gui/screen1_screen/Screen1View.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::toggleButtonClicked()
{
	if (toggleButton1.getState())
	{
		textArea1.setTypedText(touchgfx::TypedText(T_RESOURCEID3));
		textArea1.invalidate();
		textArea1.resizeToCurrentText();
		textArea1.invalidate();

		analogClock1.setTime12Hour(3, 30, 45,true);
	}
	else
	{
		textArea1.setTypedText(touchgfx::TypedText(T_RESOURCEID4));
		textArea1.invalidate();
		textArea1.resizeToCurrentText();
		textArea1.invalidate();

		analogClock1.setTime12Hour(9, 5, 25, true);
	}
}

void Screen1View::sliderChanged(int value)
{
	//touchgfx_printf("sliderChanged\n");
	const int minAlpha = 100;
	int endAngle = slider1.getValue()*360/100;
	int alphaDelta = endAngle * (255 - minAlpha) / 360;
	int seconds = slider1.getValue() * 60 / 100;

	circle1.updateArc(0, 360-endAngle);
	circle1.setAlpha(255 - alphaDelta);
	circle1.invalidate();

	analogClock1.setTime12Hour(0 , 15 + seconds/60, seconds, true);
	
}
