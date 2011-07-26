/**
	Folder:		$ mkdir /tmp/wt/; cd /tmp/wt/
	Git:			$ git clone git@gitorious.org:wt/tests.git
						$ cd tests/wt/TriggeringEvent/
	Compile:	$ cmake -DEXAMPLES_CONNECTOR="wt;wthttp"
						$ make
	Run: 			$ ./test.wt --docroot . --http-addr 0.0.0.0 --http-port 10100
*/

#include <boost/thread.hpp>
#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WStackedWidget>
#include <Wt/WWidget>
#include <Wt/WTemplate>
#include <Wt/WMenu>
#include <Wt/WDateTime>
#include <Wt/WText>
#include <Wt/WBreak>
#include <Wt/WImage>

using namespace std;
using namespace Wt;


template <typename Function>
class DeferredWidget : public Wt::WContainerWidget {
	private:
		Function f_;

		void load() {
			Wt::WContainerWidget::load();
			if (count() == 0) addWidget(f_());
		}

	public:
		DeferredWidget(Function f) : f_(f) { }
};


template <typename Function>
DeferredWidget<Function>* deferCreate(Function f) { return new DeferredWidget<Function>(f); }


class Home : public Wt::WContainerWidget {
	private:
	public:
		Home();
		virtual ~Home();
};

Home::Home() {
	WContainerWidget *cw = new 	WContainerWidget();
        cw->addWidget(new WImage("/images/Aug-cartoon.jpg "));
        cw->addWidget(new WBreak());
	//cw->addWidget(new WText("WELCOME GREAT DEVELOPERS"));
	cw->addWidget(new WBreak());
	cw->addWidget(new WBreak());
	
	cw->addWidget(new WBreak());
	cw->addWidget(new WText("Hard work is the key to sucess"));
	cw->addWidget(new WBreak());
	cw->addWidget(new WText("Failures are stepping stones for sucess"));
	cw->addWidget(new WBreak());
	cw->addWidget(new WBreak());
	cw->addWidget(new WText(" " + WDateTime::currentDateTime().toString()));
        cw->addWidget(new WBreak());
         cw->addWidget(new WBreak());
        cw->addWidget(new WText("Thanks for visit"));
	this->addWidget(cw);
}

Home::~Home() {
	
}



class About : public Wt::WContainerWidget {
	private:
	public:
		About();
		virtual ~About();
};

About::About() {
	WContainerWidget *cw = new 	WContainerWidget();
	cw->addWidget(new WText("<b>About</b> "));
	cw->addWidget(new WBreak());
	cw->addWidget(new WBreak());
        cw->addWidget(new WImage("/images/cartoon_87.gif "));
	cw->addWidget(new WText(WDateTime::currentDateTime().toString()));
	this->addWidget(cw);
}

About::~About() {
	
}
class GREATDEVELOPERS  : public Wt::WContainerWidget {
	private:
	public:
		GREATDEVELOPERS ();
		virtual ~GREATDEVELOPERS ();
};
GREATDEVELOPERS::GREATDEVELOPERS() {
	WContainerWidget *cw = new 	WContainerWidget();
	
	
        cw->addWidget(new WText(" Always rise yourself for sky"));
        cw->addWidget(new WBreak());
	cw->addWidget(new WText("Nothing is impossible because impossible itself says i am possible"));
	this->addWidget(cw);
}

GREATDEVELOPERS ::~GREATDEVELOPERS () {
	
}


class WtApplication : public WApplication {
	private:
		void msg(string str);
		Wt::WWidget *menuHome();
		Wt::WWidget *menuAbout();
                Wt::WWidget *menuGREATDEVELOPERS();
		Wt::WTemplate *staticPage(std::string str);

	public:
		WtApplication(const WEnvironment& env);
};


WtApplication::WtApplication(const WEnvironment& env) : WApplication(env) {
	msg("<b>WELCOME GREAT DEVELOPERS</b>");
	msg("");

	WStackedWidget *sw = new WStackedWidget();
	WMenu *mn = new WMenu(sw, Horizontal, 0);
	mn->setRenderAsList(true); mn->setInternalPathEnabled();

	mn->addItem("Home Page", deferCreate(boost::bind(&WtApplication::menuHome, this)))->setPathComponent("Home");
	mn->addItem("About ME", deferCreate(boost::bind(&WtApplication::menuAbout, this)))->setPathComponent("About");
       mn->addItem("GREATDEVELOPERS", deferCreate(boost::bind(&WtApplication::menuGREATDEVELOPERS, this)))->setPathComponent("GREATDEVELOPERS ");

	root()->addWidget(mn);
	root()->addWidget(sw);
	
	//msg("<p></p>Thanks for visit.");
}

WWidget* WtApplication::menuHome() { return new Home(); }

WWidget* WtApplication::menuAbout() { return new About(); }
WWidget* WtApplication::menuGREATDEVELOPERS() { return new GREATDEVELOPERS(); }
void WtApplication::msg(string str) {
	root()->addWidget(new WText(str));
	root()->addWidget(new WBreak());
}



void mThread() {
	//for (;;) {
	//	std::cout << "Delete old posted msgs " << std::endl; 
		
		
		
		//sleep(10);
	//}
}

WApplication *createApplication(const WEnvironment& env) { return new WtApplication(env); }

int main(int argc, char **argv) {
	boost::thread t1(mThread);
	
	return WRun(argc, argv, &createApplication);
}
