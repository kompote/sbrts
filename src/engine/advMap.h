/*!
 * \file advMap.h
 * \brief Map Engine Class
 * \author kompote
 * \version 0.0
 * \date 18 Octobre 2013
 *
 * Map engine class
 * Load and draw a map.
 *
 */
#ifndef ADVMAP_H
#define ADVMAP_H

#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
/*! \namespace engine
 * 
 * engine classes namespace 
 * Group every graphical concerned classes
 * 
 */
namespace engine
{
    /*! \class AdvMap
     * \brief Map engine class
     *
     *  Gère le chargement et l'affichage
     */
    class AdvMap
    {
        public:
            AdvMap();
            ~AdvMap();

            /*!
             * \brief Charge une map 
             *
             * Methode qui permet de charger une map à partir d'un fichier de
             * définition. Se charge aussi de charger le tileset
             *
             * \param filename : le nom de la map à charger
             * Correspond au nom du dossier (ex Map01)
             * \return Un code d'erreur (TODO)
             */
            unsigned char loadMap(string filename);

            /*!
             * \brief Redraw la map 
             *
             * Ne redessine que la map correspondant à la vue +/- 2 tiles,
             * en utilisant les paramètres de tailles definis par
             * setViewSize(unsigned int, unsigned int)
             *
             * \param window : affichage cible
             * \param fromX : Coordonnée X DE LA MAP duquel le redraw a lieu (en pixel)
             * \param fromY : Coordonnée Y DE LA MAP duquel le redraw a lieu (en pixel)
             */
            void redraw(RenderTarget& window, unsigned int fromX, unsigned int fromY);

            // ------------------------------------------------------------------- setViewSize
            // To set the size of the map view
            // viewX, viewY : the width and height of the view, in pixel
            /*!
             * \brief Defini la taille de la vue
             *
             * Defini la taille de la vue dans laquel la map doit
             * se dessiner
             *
             *
             * \param viewX : Taille de la vue (largeur)
             * \param viewY : Taille de la vue (hauteur)
             */
            void setViewSize(unsigned int viewX, unsigned int viewY);
        private:

            std::vector<std::vector<sf::Vector2i> > m_map;  /*!<map definition matrix */
            sf::Sprite m_tile;                              /*!<working tile */
            sf::Texture m_tileTexture;                      /*!<working texture */

            unsigned int m_uiViewWidth;                     /*!<map view size width */
            unsigned int m_uiViewHeight;                    /*!<map view size height */

    };
}
#endif
