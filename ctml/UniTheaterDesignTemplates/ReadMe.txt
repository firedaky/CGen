Templates

	Zwei Fälle: Zugriff auf Template (Template in anderes Template inkludieren) oder Template definieren, sollte das Template in einer eigenen File sein ist das Attribut name des Templates der Dateiname (ohne Endung *.ctml)

	<CGenTemplate name = "placeolder" />
	
				----> 	inkludiere Template in Datei placeolder.ctml ein mal

	<CGenTemplate name = "placeholder" multiplicity = "*">

				----> 	inkludiere Template in Datei placeolder.ctml so oft wie möglich (durch Liste definiert)

	<CGenTemplate name = "placeholder" multiplicity = "n">

				----> 	inkludiere Template in Datei placeolder.ctml n mal


	<CGenTemplate name = "placeolder">

				----> 	inline defintion des Templates placeholder, 
						Gültigkeitsbereich: in der betreffenden Template-Datei 
						multiplicitys identisch

	</CGenTemplate>


Content-Typen

	Multiplicity Rules gleich den bekannten Multiplicity Rules der Templates

	<CGenContent type = "typDef" {multiplcity = "*"}/>

	Mögliche Werte von typDef sind:

		link 		--> Erwartet wird: der Link und ein Alternativtext
		image		--> Erwartet wird: Pfad zum Bild und ein Alternativtext
		text		--> Erwartet wird: ein Text
		int			--> Erwartet wird: ein integer Wert
