#include "svg.h"
#include <iostream>

string text_decoration18(size_t bin)
{
size_t k=-1;
while ((k<0) or (k>3)){
cerr<<endl;
cerr<<"Now choose the text of "<<bin+1<<" column"<<endl;
cerr<<"0 - none"<<endl;
cerr<<"1 - underline"<<endl;
cerr<<"2 - overline"<<endl;
cerr<<"3 - line-through"<<endl;
cerr<<"If you enter another number you will have one more try!"<<endl;
cin>>k;
}
if (k==0) return "none";
if (k==1) return "underline";
if (k==2) return "overline";
if (k==3) return "line-through";
}

void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end()
{
    cout << "</svg>\n";
}

void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black")
{
    cout << "<rect x='"<<x<<"' y='"<<y<<"' width='"<<width<<"' height='"<<height<<"' stroke='"<<stroke<<"' fill='"<<fill<<"' />";
}

void svg_text(double left, double baseline, string text,string text_decoration = "none")
{
    cout << "<text x='" << left << "' y='"<<baseline<<"' text-decoration='"<<text_decoration<<"'>"<<text<<"</text>";

}
void show_histogram_svg(const vector<size_t>& bins)
{
    const size_t screen_width=80;
    const size_t width=screen_width-4;
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    const auto GRAPH_WIDTH = IMAGE_WIDTH-TEXT_WIDTH;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    string stroke="gold";
    string fill="maroon";
    size_t max_count = 0;
    for (size_t count : bins)
    {
        if (count > max_count)
        {
            max_count = count;
        }
    }

    const bool scaling_needed = max_count > width;

    if (scaling_needed)
    {
        const double scaling_multiplier = (double)width / max_count;
        if(max_count*BLOCK_WIDTH/GRAPH_WIDTH>1)
        {
            for (size_t bin : bins)
            {
                const double new_scaling_multiplier=(double)GRAPH_WIDTH/(max_count*BLOCK_WIDTH*scaling_multiplier);
                const size_t new_bin_width = (size_t)BLOCK_WIDTH*bin*scaling_multiplier*new_scaling_multiplier;
                svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin),text_decoration18(bin));
                svg_rect(TEXT_WIDTH, top, new_bin_width, BIN_HEIGHT,stroke,fill);
                top += BIN_HEIGHT;
            }
        }
        else
        {
            for (size_t bin : bins)
            {
                const double bin_width = BLOCK_WIDTH*bin*scaling_multiplier;
                svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin),text_decoration18(bin));
                svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT,stroke,fill);
                top += BIN_HEIGHT;
            }
        }
    }

    else
    {
        if(max_count*BLOCK_WIDTH/GRAPH_WIDTH>1)
        {
            for (size_t bin : bins)
            {
                const double new_scaling_multiplier=(double)GRAPH_WIDTH/(max_count*BLOCK_WIDTH);
                const size_t new_bin_width = (size_t)BLOCK_WIDTH*bin*new_scaling_multiplier;
                svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin),text_decoration18(bin));
                svg_rect(TEXT_WIDTH, top, new_bin_width, BIN_HEIGHT,stroke,fill);
                top += BIN_HEIGHT;
            }
        }
        else
        {
            for (size_t bin : bins)
            {
                const double bin_width = BLOCK_WIDTH * bin;
                svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin),text_decoration18(bin));
                svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT,stroke,fill);
                top += BIN_HEIGHT;
            }
        }
    }
    svg_end();
}
