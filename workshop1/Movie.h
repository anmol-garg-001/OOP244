//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
// Name : Anmol Garg
// Student ID: 149916199
// Student email: agarg15@myseneca.ca
// Date : 22 Sept, 2020

#ifndef SDDS_MOVIE_H 
#define SDDS_MOVIE_H

// Your header file content goes here
namespace sdds {
	struct Movie {
		char m_title[128];
		int m_year;
		char m_rating[6];
		int m_duration;
		char m_genres[10][11];
		float m_consumerRating;
	};

	bool loadMovies();
	bool hasGenre(const Movie* mvp, const char genre[]);
	void displayMovie(const Movie* mvp);
	void displayMoviesWithGenre(const char genre[]);
}
#endif