#include <Wt/WApplication>

#include <Wt/WBorderLayout>
#include <Wt/WText>
#include <Wt/WHBoxLayout>
#include <Wt/WAnchor>
#include <Wt/WImage>
#include <Wt/WMessageBox>
#include <Wt/Ext/Panel>
#include <Wt/WFitLayout>

using namespace Wt;

class HelloApplication : public WApplication

{
public:
  HelloApplication(const WEnvironment& env);
 std::string store;

};
HelloApplication::HelloApplication(const WEnvironment& env)
  : WApplication(env)
{

  setTitle("Rupinder"); 

Wt::WContainerWidget *j = new Wt::WContainerWidget(root());
 j->resize(WLength::Auto, 330);



 Wt::WBorderLayout *lat = new Wt::WBorderLayout();
//lay->addWidget(new Wt::WText("this site is made by rupinder. \n who are pursuing is b.tech from gndec ludhiana."),0,0);
 lat->addWidget(new Wt::WImage("/images/logo.png "),Wt::WBorderLayout::Center);


 j->setLayout(lat);	
 
StandardButton
   result = WMessageBox::show("WELCOME USERS", " Please click ok to see TCC WEBSITE ",
                              Ok );
WCssDecorationStyle& decoration=root()->decorationStyle();

      decoration.setBackgroundColor(WColor("#ADA96E"));
      decoration.setForegroundColor(black);

root()->addWidget(new WText("<h1><center>TRAINING AND CONSULTANCY CELL</center></h1> "));
Wt::WContainerWidget *l = new Wt::WContainerWidget(root());
  l->resize(WLength::Auto, 50);
 Wt::WHBoxLayout *layo = new Wt::WHBoxLayout();
 layo->addWidget(new Wt::WAnchor("http://gndec.ac.in/~tcc/", "INTRODUCTION", root()));
 layo->addWidget(new Wt::WAnchor("http://gndec.ac.in", "GNDEC", root()));
layo->addWidget(new Wt::WAnchor("http://rupjat.wordpress.com/", "Rupinder", root()));
layo->addWidget(new Wt::WAnchor("http://rupjat.wordpress.com/", "About us", root()));

 /*layo->addWidget(new Wt::WText(store));
 layo->addWidget(new Wt::WImage("/images/rai.jpeg ", root()));*/
 l->setLayout(layo);


Wt::WContainerWidget *p = new Wt::WContainerWidget(root());
 p->resize(WLength::Auto, 200);


 Wt::WGridLayout *lay = new Wt::WGridLayout();
//lay->addWidget(new Wt::WText("this site is made by rupinder kaur. \n who are pursuing is b.tech from gndec ludhiana."),0,0);
 lay->addWidget(new Wt::WImage("/images/rais.jpg "), 0,2);

//lay->addWidget(new Wt::WImage("/images/abc.jpg "), 0,3);

lay->addWidget(new Wt::WText("Guru Nanak dev Engineering college is the most prominent institute in north india  "), 0,0);
store="<p>Consultancy Services are being rendered by various Departments of the College to the industry," 
      " Sate Government Departments and Entrepreneurs and are extended in the form of expert advice in "
      "design, testing of materials & equipment, technical surveys, technical audit, caliberation of " 
      " instruments, prepartion of technicalfeasibility reports etc.</p> This consultancy cell of the college has given a new dimension to the development programmes of the College. Consultancy projects of over Rs. one crore are completed by the Consultancy cell during financial year 2009-10. ";
lay->addWidget(new Wt::WText(store),0,1);
 p->setLayout(lay);
Wt::WContainerWidget *z = new Wt::WContainerWidget(root());
  z->resize(WLength::Auto, 50);
Wt::WGridLayout *go = new Wt::WGridLayout();
go->addWidget(new Wt::WText(" Rai Sir is the prominent figure in gne"),0,2);
z->setLayout(go);

Wt::WContainerWidget *w = new Wt::WContainerWidget(root());
w->resize(WLength::Auto, 500);
 Wt::WBorderLayout *out = new Wt::WBorderLayout();
//out->addWidget(new Wt::WText(store),Wt::WBorderLayout::Center);
 
out->addWidget(new Wt::WText("THANKS FOR VISITING "), Wt::WBorderLayout::South);
 

 // use layout but do not justify vertically
 w->setLayout(out);

 
}
WApplication *createApplication(const WEnvironment& env)
{
 
  return new HelloApplication(env);
}

int main(int argc, char **argv)
{
 
  return WRun(argc, argv, &createApplication);
}

