//============================================================================
// Name        : Newsie.cpp
// Author      : Timothy Goon, Patrick Houlihan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Newsie.h"

//These are done C style with char array strings
//When you port this to C++, you are ENCOURAGED to use strings
//Though you might want to keep char array stuff for fscanf input
//Do investigate how C++ works with char array strings.  Easy conversion?

// Newsie constructor
Newsie::Newsie(std::string first, std::string last, float gpa, int id, position title,
article primary, article secondary, article tertiary, int term_goal, int term_kount, int terms,
        std::string non_de_plume){
first_ = first;
last_ = last;
gpa_ = gpa;
id_ = id;
title_ = title;
primary_ = primary;
secondary_ = secondary;
tertiary_ = tertiary;
term_goal_ = term_goal;
term_kount_ = term_kount;
terms_ = terms;
non_de_plume_ = non_de_plume;
current_priority_ = nullptr;
current_extra_ = nullptr;
current_emergency_ = nullptr;
}

// Deconstructor
Newsie::~Newsie(){

}

// getter for title
position Newsie::getTitle(){
    return title_;
}

// getter for primary
article Newsie::getPrimary(){
    return this->primary_;
}

// getter for secondary
article Newsie::getSecondary(){
    return this->secondary_;
}

// getter for tertiary
article Newsie::getTertiary(){
    return this->tertiary_;
}

// getter for term_goal
int Newsie::getTerm_goal(){
    return term_goal_;
}

// getter for term_count
int Newsie::getTerm_count(){
    return term_kount_;
}

// getter for terms
int Newsie::getTerms(){
    return terms_;
}

// getter for non_de_plume
std::string Newsie::getNon_de_plume(){
    return non_de_plume_;
}

// getter for current_priority
Assignment* Newsie::getCurrent_priority(){
    return current_priority_;
}

// getter for current_extra
Assignment* Newsie::getCurrent_extra(){
    return current_extra_;
}

// getter for current emergency
Assignment* Newsie::getCurrent_emergency(){
    return current_emergency_;
}

// setter for current_priority
void Newsie::setCurrent_priority(Assignment* prio){
    current_priority_ = prio;
}

// setter for current_extra
void Newsie::setCurrent_extra(Assignment* prio){
    current_extra_ = prio;
}

// setter for current_emergency
void Newsie::setCurrent_emergency(Assignment* prio){
    current_emergency_ = prio;
}

bool Newsie::getAndCompareTertiary(article tertiary) {
    return tertiary == tertiary_;
}
bool Newsie::getAndCompareSecondary(article secondary) {
    return secondary == secondary_;
}
bool Newsie::getAndComparePrimary(article primary) {
    return primary = primary_;
}

bool allDiscovered (std::vector<Assignment> assignment) {
    for (int i = 0; i < assignment.size(); i++) {
        if (!assignment[i].getAssigned()) {
            return false;
        }
    }
    return true;
}

void printStudentAssignments (std::vector<Newsie> newsies, std::vector<Assignment> assignments) {
    for (auto student : newsies) {
        std::cout << student.first_name() << " " << student.getNon_de_plume() << " " << student.last_name() << " ";
        if (student.getTitle() == 0) {
            std::cout << "Editor " << std::endl;
        }
        if (student.getTitle() == 1) {
            std::cout << "Deputy_Editor " << std::endl;
        }
        if (student.getTitle() == 2) {
            std::cout << "Assistant_Editor " << std::endl;
        }
        if (student.getTitle() == 3) {
            std::cout << "Reporter " << std::endl;
        }
        if (student.getTitle() == 4) {
            std::cout << "Cub_Reporter " << std::endl;
        }
        for (auto assignment : assignments) {
            if (assignment.getAssignedNewsie().full_name() == student.full_name()) {
                std::cout << "     " << assignment.getTempTitle() << std::endl;

            }
        }
        std::cout << std::endl;
    }
}

void printWeeklyAssignments(std::vector<Newsie> newsies, std::vector<Assignment> assignments) {
    for (auto student : newsies) {
        std::cout << student.last_name() << " ";
        if (student.getTitle() == 0) {
            std::cout << "Editor ";
        }
        if (student.getTitle() == 1) {
            std::cout << "Deputy_Editor ";
        }
        if (student.getTitle() == 2) {
            std::cout << "Assistant_Editor ";
        }
        if (student.getTitle() == 3) {
            std::cout << "Reporter ";
        }
        if (student.getTitle() == 4) {
            std::cout << "Cub_Reporter ";
        }
        for (auto assignment : assignments) {
            if (assignment.getAssignedNewsie().full_name() == student.full_name()) {
                std::cout << assignment.getTempTitle() << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

int main() {
	puts("Some terminal and file I/O!"); /* prints !!!Hello World!!! */


	// Pointer to the file
     FILE *NewsiesFP;

     // Opening a file in r mode
     NewsiesFP = fopen("NewsiesStaff.txt", "r");

     if (NewsiesFP == NULL)
     {
         printf("Can't find file");
     }

     char firstname_[30];
     char lastname_[30];
     float gpa_;
     int IDnum_;

     position title_;

     article primary_;
     article secondary_;
     article tertiary_;

     int term_goal_;
     int term_kount_;
     int terms_;

     char non_de_plume_[30];

     // Get the file sentinel
     int sentinel = 0;
     fscanf(NewsiesFP, "%d", &sentinel);
     printf("\nNewsie Staff Info\n");

     // Read in all newsies in the file and create a vector of newsie objects
     std::vector<Newsie> newsies;
     for (int kount = 1; kount <= sentinel;kount++){

        fscanf(NewsiesFP, "%s %s %f %d %d %d %d %d %d %d %d %s", firstname_, lastname_, &gpa_, &IDnum_, &title_, &primary_, &secondary_,
                &tertiary_, &term_goal_, &term_kount_, &terms_, non_de_plume_ );

        // Convert char* to std::string
        std::string fName = std::string(firstname_);
        std::string lName = std::string(lastname_);
        std::string NDP = std::string(non_de_plume_);
        newsies.emplace_back(Newsie(fName, lName, gpa_, IDnum_, title_, primary_, secondary_, tertiary_, term_goal_, term_kount_, terms_, NDP));
     }

     fclose(NewsiesFP);

     // display the info for all of the newsies
     for(auto student : newsies){
         student.print_info();
     }

     // Pointer to the file
     FILE *AssignmentDeskFP;

     // Opening a file in r mode
     AssignmentDeskFP = fopen("AssignmentEditorTxt.txt", "r");

     if (AssignmentDeskFP == NULL)
     {
         printf("Can't find file");
     }

     article desk;
     char temptitle[80];

     fscanf(AssignmentDeskFP, "%d", &sentinel);

    printf("\nAssignment Desk\n");

    std::vector<Assignment> assignments;
    for (int kount = 1; kount <= sentinel;kount++){

        fscanf(AssignmentDeskFP, "%d %s", &desk, temptitle);

        std::string tempTitle = std::string(temptitle);
        assignments.emplace_back(Assignment(desk, tempTitle));
     }

     fclose(AssignmentDeskFP);

    for(auto assignment : assignments){
        assignment.print();
    }

    while (!allDiscovered(assignments)) {
        for (auto student : newsies) {
            for (int i = 0; i < assignments.size(); i++) {
                //Checks if the assignment is in the students purview
                if ((student.getPrimary() == assignments[i].getDesk())
                    && !assignments[i].getAssigned()) {
                    //sets current priority to whatever assignment it matched
                    if (student.getCurrent_priority() == nullptr) {
                        student.setCurrent_priority(&assignments[i]);
                        assignments[i].setAssigned(true);
                        assignments[i].setAssignedNewsie(student);
                    }
                    //sets current priority to whatever assignment it matched
                    if (student.getCurrent_extra() == nullptr) {
                        student.setCurrent_extra(&assignments[i]);
                        assignments[i].setAssigned(true);
                        assignments[i].setAssignedNewsie(student);
                    }
                    //sets current priority to whatever assignment it matched
                    if (student.getCurrent_priority() == nullptr) {
                        student.setCurrent_priority(&assignments[i]);
                        assignments[i].setAssigned(true);
                        assignments[i].setAssignedNewsie(student);
                    }
                }
                //Checks if the assignment is in the students purview
                if ((student.getSecondary() == assignments[i].getDesk())
                    && !assignments[i].getAssigned()) {
                    //sets current priority to whatever assignment it matched
                    if (student.getCurrent_priority() == nullptr) {
                        student.setCurrent_priority(&assignments[i]);
                        assignments[i].setAssigned(true);
                        assignments[i].setAssignedNewsie(student);
                    }
                    //sets current priority to whatever assignment it matched
                    if (student.getCurrent_extra() == nullptr) {
                        student.setCurrent_extra(&assignments[i]);
                        assignments[i].setAssigned(true);
                        assignments[i].setAssignedNewsie(student);
                    }
                    //sets current priority to whatever assignment it matched
                    if (student.getCurrent_priority() == nullptr) {
                        student.setCurrent_priority(&assignments[i]);
                        assignments[i].setAssigned(true);
                        assignments[i].setAssignedNewsie(student);
                    }
                }
                //Checks if the assignment is in the students purview
                if ((student.getTertiary() == assignments[i].getDesk())
                    && !assignments[i].getAssigned()) {
                    //sets current priority to whatever assignment it matched
                    if (student.getCurrent_priority() == nullptr) {
                        student.setCurrent_priority(&assignments[i]);
                        assignments[i].setAssigned(true);
                        assignments[i].setAssignedNewsie(student);
                    }
                    //sets current priority to whatever assignment it matched
                    if (student.getCurrent_extra() == nullptr) {
                        student.setCurrent_extra(&assignments[i]);
                        assignments[i].setAssigned(true);
                        assignments[i].setAssignedNewsie(student);
                    }
                    //sets current priority to whatever assignment it matched
                    if (student.getCurrent_priority() == nullptr) {
                        student.setCurrent_priority(&assignments[i]);
                        assignments[i].setAssigned(true);
                        assignments[i].setAssignedNewsie(student);
                    }
                }
            }
        }
    }

    std::cout<< std::endl<<std::endl;

    for(auto assignment : assignments){
        assignment.print();
    }
    printStudentAssignments(newsies, assignments);
    printWeeklyAssignments(newsies, assignments);




	return 0;
}
