/*
 * informes.h
 *
 *  Created on: 21 jun. 2021
 *      Author: santi
 */

#ifndef SRC_INFORMES_H_
#define SRC_INFORMES_H_

int inf_infomar(Dictionary* art,Dictionary* ara,Maritimo esMaritimo,Aereo esAereo);

int inf_calCostoArgentino(float baseImponible,Arancel* pAracel,float* resultado);

int inf_calBaseImponible(Articulo* art,Arancel* ara,float flete,float* resultado);
int inf_calFleteMaritimo(Articulo* art,Maritimo esMaritimo,float* resultado);

int inf_claFleteAereo(Articulo* art,Aereo esAereo,float* resultado);


Arancel* inf_getArancelDeUnArticulo(Articulo* pArticulo,Dictionary* ara);

#endif /* SRC_INFORMES_H_ */
