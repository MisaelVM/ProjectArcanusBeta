#include "TileMap.h"

TileMap::TileMap(int rows, int columns, std::string archive, const char* tilemapArchive) {
	//Leer un archivo
	char aux; //esto me servira para leer el archivo para poder sacar los char del archivo
	FILE** TilemapArchive; //Doble puntero porque VS no me deja abrirlo si no es con la funcion fopen_s(abrir de forma segura) que recibe como argumento un puntero a puntero
	TilemapArchive = new FILE*;
	fopen_s(TilemapArchive, tilemapArchive, "r");
	if (TilemapArchive == NULL) {
		std::cout << "Archivo no encontrado";
		exit(1);
	}
	this->rows = rows;
	this->columns = columns;
	sizeoftile = 35;
	image = std::make_unique<sf::Texture>();
	image->loadFromFile(archive);
	// hitbox = new sf::RectangleShape();
	// hitbox->setSize(sf::Vector2f(35.0f, 35.0f));
	// hitbox->setOrigin(hitbox->getSize() / 2.0f);
	Tile = std::make_unique<sf::Sprite>();
	Mtile = new char* [this->rows];
	for (int i = 0; i < this->rows; i++)
		Mtile[i] = new char[this->columns];

	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			aux = fgetc(*TilemapArchive);
			if (aux != ' ' && aux != '\n')
				Mtile[i][j] = aux;
			else
				Mtile[i][j] = fgetc(*TilemapArchive);
		}
	}
	fclose(*TilemapArchive);
	//Iniciando el arreglo de tiles, ponerlo en orden y con su respectiva letra, el map se ordena por orden alfabetico
	ArrayTile["aa_arbolplantado"];
	ArrayTile["ab_pasto1"];
	ArrayTile["ac_pasto2"];
	ArrayTile["ad_puertaopen1"];
	ArrayTile["ae_puertaclose1"];
	ArrayTile["af_pasto3"];
	ArrayTile["ag_pasto4"];
	ArrayTile["ah_raizizqarboleda"];
	ArrayTile["ai_raizderarboleda"];
	ArrayTile["aj_raizizq"];
	ArrayTile["ak_raizder"];
	ArrayTile["al_raiz"];
	ArrayTile["am_arbol1"];
	ArrayTile["an_casa1"];
	ArrayTile["ao_casa2"];
	ArrayTile["ap_casa3"];
	ArrayTile["aq_flores"];
	ArrayTile["ar_columnacasa1"];
	ArrayTile["as_columnacasa2"];
	ArrayTile["at_puertaopen2"];
	ArrayTile["au_puertaclose2"];
	ArrayTile["av_pasto5"];
	ArrayTile["aw_pasto6"];
	ArrayTile["ax_raizizqcortadaarboleda"];
	ArrayTile["ay_raizdercortadaarboleda"];
	ArrayTile["az_raizizqcortada"];
	ArrayTile["ba_raizdercortada"];
	ArrayTile["bb_raizcortada"];
	ArrayTile["bc_arbol2"];
	ArrayTile["bd_casa4"];
	ArrayTile["be_casa5"];
	ArrayTile["bf_casa6"];
	ArrayTile["bg_arbustos"];
	ArrayTile["bh_entradacasa1"];
	ArrayTile["bi_entradacasa2"];
	ArrayTile["bj_entradacasa3"];
	ArrayTile["bk_ventana1"];
	ArrayTile["bl_ventana2"];
	ArrayTile["bm_pasto7"];
	ArrayTile["bn_pasto8"];
	ArrayTile["bo_raizderizq"];
	//ArrayTile["bp_raizizqgruesa"];
	ArrayTile["bq_trozodemadera"];
	ArrayTile["br_monte1"];
	ArrayTile["bs_monte2"];
	ArrayTile["bt_arbol3"];
	ArrayTile["bu_casa7"];
	ArrayTile["bv_casa8"];
	ArrayTile["bw_casa9"];
	ArrayTile["bx_empedrado1"];
	ArrayTile["by_empedrado2"];
	ArrayTile["bz_empedrado3"];
	ArrayTile["ca_empedrado4"];
	ArrayTile["cb_empedrado5"];
	ArrayTile["cc_empedrado6"];
	ArrayTile["cd_tumba"];
	ArrayTile["ce_puente1"];
	ArrayTile["cf_puente2"];
	ArrayTile["cg_puente3"];
	ArrayTile["ch_monte3"];
	ArrayTile["ci_monte4"];
	ArrayTile["cj_arbol4"];
	ArrayTile["ck_casa10"];
	ArrayTile["cl_casa11"];
	ArrayTile["cm_casa12"];
	ArrayTile["cn_empedrado7"];
	ArrayTile["co_empedrado8"];
	ArrayTile["cp_empedrado9"];
	ArrayTile["cq_empedrado10"];
	ArrayTile["cr_empedrado11"];
	ArrayTile["cs_empedrado12"];
	ArrayTile["ct_pozo1"];
	ArrayTile["cu_pozo2"];
	ArrayTile["cv_pozo3"];
	ArrayTile["cw_pozo4"];
	ArrayTile["cx_pozo5"];
	ArrayTile["cy_pozo6"];
	ArrayTile["cz_barril1"];
	ArrayTile["da_columnacasa3"];
	ArrayTile["db_barro1"];
	ArrayTile["dc_columnacasa4"];
	ArrayTile["dd_pasto9"];
	ArrayTile["de_empedrado13"];
	ArrayTile["df_empedrado14"];
	ArrayTile["dg_empedrado15"];
	ArrayTile["dh_empedrado16"];
	ArrayTile["di_empedrado17"];
	ArrayTile["dj_barro2"];
	ArrayTile["dk_barro3"];
	ArrayTile["dl_barril2"];
	ArrayTile["dm_pozo7"];
	ArrayTile["dn_pozo8"];
	ArrayTile["do_pozo9"];
	ArrayTile["dp_barril3"];
	ArrayTile["dq_entradacasa4"];
	ArrayTile["dr_entradacasa5"];
	ArrayTile["ds_entradacasa6"];
	ArrayTile["dt_montana1"];
	ArrayTile["du_montana2"];
	ArrayTile["dv_montana3"];
	ArrayTile["dw_montana4"];
	ArrayTile["dx_montana5"];
	ArrayTile["dy_valla1"];
	ArrayTile["dz_empedrado18"];
	ArrayTile["ea_empedrado19"];
	ArrayTile["eb_empedrado20"];
	ArrayTile["ec_empedrado21"];
	ArrayTile["ed_ignore1"];
	ArrayTile["ee_ignore2"];
	ArrayTile["ef_ignore3"];
	ArrayTile["eg_ignore4"];
	ArrayTile["eh_ignore5"];
	ArrayTile["ei_ignore6"];
	ArrayTile["ej_montana6"];
	ArrayTile["ek_montana7"];
	ArrayTile["el_montana8"];
	ArrayTile["em_montana9"];
	ArrayTile["en_montana10"];
	ArrayTile["eo_valla2"];
	ArrayTile["ep_otroarbol1"];
	ArrayTile["eq_arbolizq1"];
	ArrayTile["er_arbolder1"];
	ArrayTile["es_arbolderizq1"];
	ArrayTile["et_arbolgruesoizq1"];
	ArrayTile["eu_arbolgruesoder1"];
	ArrayTile["ev_arboleda1"];
	ArrayTile["ew_ignore7"];
	ArrayTile["ex_ignore8"];
	ArrayTile["ey_ignore9"];
	ArrayTile["ez_montana11"];
	ArrayTile["fa_montana12"];
	ArrayTile["fb_montana13"];
	ArrayTile["fc_montana14"];
	ArrayTile["fd_montana15"];
	ArrayTile["fe_valla3"];
	ArrayTile["ff_otroarbol2"];
	ArrayTile["fg_arbolizq2"];
	ArrayTile["fh_arbolder2"];
	ArrayTile["fi_arbolderizq2"];
	ArrayTile["fj_arbolgruedoizq2"];
	ArrayTile["fk_arbolgruesoder2"];
	ArrayTile["fl_arboleda2"];
	ArrayTile["fm_ignore10"];
	ArrayTile["fn_ignore11"];
	ArrayTile["fo_ignore12"];
	ArrayTile["fp_montana16"];
	ArrayTile["fq_montana17"];
	ArrayTile["fr_montana18"];
	ArrayTile["fs_montana19"];
	ArrayTile["ft_montana20"];
	ArrayTile["fu_valla4"];
	ArrayTile["fu_valla4ignored"];
	ArrayTile["fv_arbolizq3"];
	ArrayTile["fw_arbolder3"];
	ArrayTile["fx_arbolderizq3"];
	ArrayTile["fy_arbolgruedoizq3"];
	ArrayTile["fz_arbolgruesoder3"];
	ArrayTile["ga_arboleda3"];
	ArrayTile["gb_ignore13"];
	ArrayTile["gc_ignore14"];
	ArrayTile["gd_ignore15"];
	ArrayTile["ge_montana21"];
	ArrayTile["gf_montana22"];
	ArrayTile["gg_montana23"];
	ArrayTile["gh_montana24"];
	ArrayTile["gi_montana25"];
	ArrayTile["gj_valla5"];
	ArrayTile["gj_valla5ignored"];
	ArrayTile["gk_arbolizq4"];
	ArrayTile["gl_arbolder4"];
	ArrayTile["gm_arbolderizq4"];
	ArrayTile["gn_arbolgruedoizq4"];
	ArrayTile["go_arbolgruesoder4"];
	ArrayTile["gp_arboleda4"];
	ArrayTile["gq_ignore16"];
	ArrayTile["gr_ignore17"];
	ArrayTile["gs_ignore18"];
	/*ArrayTile["gt_"];
	ArrayTile["gu_"];
	ArrayTile["gv_"];
	ArrayTile["gw_"];
	ArrayTile["gx_"];
	ArrayTile["gy_"];
	ArrayTile["gz_"];
	ArrayTile["ha_"];*/

	std::map<std::string, sf::Sprite>::iterator i; //Se declara "i" como iterador de nuestro map
	int f = 0, c = 0;
	for (i = ArrayTile.begin(); i != ArrayTile.end(); i++)
	{
		i->second.setTexture(*image);
		i->second.setTextureRect(sf::IntRect(f * 16, c * 16, 16, 16)); //Los numeros dependeran de cuantos pixeles ocupa su textura en la imagen y de igual modo el escalado
		i->second.setScale(sizeoftile / 16.0f, sizeoftile / 16.0f);
		f++;
		if (f == 16) //Este numero 15 ya depende de cuantas texturas hay en la fila de su imagen que contiene las texturas
		{
			c++;
			f = 0;
		}
	}
}

TileMap::TileMap() {
	rows = 0;
	columns = 0;
	sizeoftile = 0;
	image = std::make_unique<sf::Texture>();
	image->loadFromFile("Texturadefault.jpg");
	Tile = std::make_unique<sf::Sprite>();
	// hitbox = new sf::RectangleShape();
	Mtile = new char* [1];
	for (int i = 0; i < 1; i++)
		Mtile[i] = new char[1];
}

TileMap::~TileMap() {
	for (int i = 0; i < rows; i++)
		delete[] Mtile[i];
	delete[] Mtile;
}

sf::Sprite TileMap::GetTile(int row, int column) {
	switch (*(*(Mtile + row) + column)) {
	case 'a':
		*Tile = ArrayTile["an_casa1"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'b':
		*Tile = ArrayTile["ao_casa2"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'c':
		*Tile = ArrayTile["ap_casa3"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'd':
		*Tile = ArrayTile["bd_casa4"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'e':
		*Tile = ArrayTile["be_casa5"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'f':
		*Tile = ArrayTile["bf_casa6"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'g':
		*Tile = ArrayTile["bu_casa7"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'h':
		*Tile = ArrayTile["bv_casa8"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'i':
		*Tile = ArrayTile["bw_casa9"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'j':
		*Tile = ArrayTile["ck_casa10"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'k':
		*Tile = ArrayTile["cl_casa11"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'l':
		*Tile = ArrayTile["cm_casa12"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'm':
		*Tile = ArrayTile["da_columnacasa3"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'n':
		*Tile = ArrayTile["ae_puertaclose1"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'o':
		*Tile = ArrayTile["dc_columnacasa4"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'p':
		*Tile = ArrayTile["ar_columnacasa1"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'q':
		*Tile = ArrayTile["au_puertaclose2"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'r':
		*Tile = ArrayTile["as_columnacasa2"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 's':
		*Tile = ArrayTile["bh_entradacasa1"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 't':
		*Tile = ArrayTile["bi_entradacasa2"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'u':
		*Tile = ArrayTile["bj_entradacasa3"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'v':
		*Tile = ArrayTile["dq_entradacasa4"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'w':
		*Tile = ArrayTile["dr_entradacasa5"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'x':
		*Tile = ArrayTile["ds_entradacasa6"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'y':
		*Tile = ArrayTile["aq_flores"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'z':
		*Tile = ArrayTile["bg_arbustos"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case '1':
		*Tile = ArrayTile["ct_pozo1"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case '2':
		*Tile = ArrayTile["cu_pozo2"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case '3':
		*Tile = ArrayTile["cv_pozo3"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case '4':
		*Tile = ArrayTile["cw_pozo4"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case '5':
		*Tile = ArrayTile["cx_pozo5"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case '6':
		*Tile = ArrayTile["cy_pozo6"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case '7':
		*Tile = ArrayTile["dm_pozo7"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case '8':
		*Tile = ArrayTile["dn_pozo8"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case '9':
		*Tile = ArrayTile["do_pozo9"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case '0':
		*Tile = ArrayTile["cd_tumba"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'A':
		*Tile = ArrayTile["ab_pasto1"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'B':
		*Tile = ArrayTile["aa_arbolplantado"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'C':
		*Tile = ArrayTile["am_arbol1"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'D':
		*Tile = ArrayTile["bc_arbol2"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'E':
		*Tile = ArrayTile["bt_arbol3"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'F':
		*Tile = ArrayTile["cj_arbol4"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'G':
		*Tile = ArrayTile["al_raiz"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'H':
		*Tile = ArrayTile["er_arbolder1"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'I':
		*Tile = ArrayTile["fh_arbolder2"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'J':
		*Tile = ArrayTile["fw_arbolder3"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'K':
		*Tile = ArrayTile["gl_arbolder4"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'L':
		*Tile = ArrayTile["ak_raizder"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'M':
		*Tile = ArrayTile["eq_arbolizq1"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'N':
		*Tile = ArrayTile["fg_arbolizq2"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'O':
		*Tile = ArrayTile["fv_arbolizq3"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'P':
		*Tile = ArrayTile["gk_arbolizq4"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'R':
		*Tile = ArrayTile["aj_raizizq"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'S':
		*Tile = ArrayTile["eo_valla2"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'T':
		*Tile = ArrayTile["fe_valla3"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'U':
		*Tile = ArrayTile["gj_valla5"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'V':
		*Tile = ArrayTile["fu_valla4"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'W':
		*Tile = ArrayTile["bx_empedrado1"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'X':
		*Tile = ArrayTile["by_empedrado2"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'Y':
		*Tile = ArrayTile["cn_empedrado7"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case 'Z':
		*Tile = ArrayTile["cb_empedrado5"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case '!':
		*Tile = ArrayTile["db_barro1"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case '"':
		*Tile = ArrayTile["cz_barril1"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case '#':
		*Tile = ArrayTile["dl_barril2"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case '$':
		*Tile = ArrayTile["dp_barril3"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case '%':
		*Tile = ArrayTile["ev_arboleda1"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case '&':
		*Tile = ArrayTile["fl_arboleda2"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case '/':
		*Tile = ArrayTile["ga_arboleda3"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	case '(':
		*Tile = ArrayTile["gp_arboleda4"];
		Tile->setPosition(sizeoftile * column, sizeoftile * row);
		break;
	}
	return *Tile;
}

void TileMap::Displaytilemap(sf::RenderTarget* window, sf::Vector2f viewposition) {
	//window->draw(*hitbox);
	for (int i = ceil(viewposition.y / sizeoftile) - 10; i < ceil(viewposition.y / sizeoftile) + 10; i++)
		for (int j = ceil(viewposition.x / sizeoftile) - 13; j < ceil(viewposition.x / sizeoftile) + 12; j++)
			window->draw(this->GetTile(i, j));
	// window->draw(*hitbox);
}

char TileMap::GetChar(int rows, int colums) {
	return *(*(Mtile + rows) + colums);
}

/*sf::RectangleShape TileMap::GetCaja(sf::Vector2f hitboxposition) {
	int row=ceil((hitboxposition.y-17.5f)/35);
	int colum=ceil((hitboxposition.x-17.5f)/35);
	if (GetChar(row, colum) == '"') {

		hitbox->setSize(sf::Vector2f(35.0f, 35.0f));
		hitbox->setOrigin(hitbox->getSize() / 2.0f);
		hitbox->setPosition(35.0f * (colum + 1) - 17.5f, 35.0f * (row + 1) - 17.5f);
	}
	else if (GetChar(row, colum) == '#') {
		hitbox->setSize(sf::Vector2f(35.0f, 35.0f));
		hitbox->setOrigin(hitbox->getSize() / 2.0f);
		hitbox->setPosition(35.0f * (colum + 1) - 17.5f, 35.0f * (row + 1) - 17.5f);
	}
	else if (GetChar(row, colum) == '$') {
		hitbox->setSize(sf::Vector2f(35.0f, 35.0f));
		hitbox->setOrigin(hitbox->getSize() / 2.0f);
		hitbox->setPosition(35.0f * (colum + 1) - 17.5f, 35.0f * (row + 1) - 17.5f);
	}
	else {
		hitbox->setSize(sf::Vector2f(35.0f, 35.0f));
		hitbox->setOrigin(hitbox->getSize() / 2.0f);
		hitbox->setPosition(- 17.5f, - 17.5f);
	}
	return *hitbox;
}*/