<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
<xsl:template match="blibliotheque">
    <html>
            <head>
                <link href="style.css" type="text/css" rel="stylesheet"></link>
            </head>
	<body>
            <xsl:apply-templates />
	</body>	
    </html>
</xsl:template>

<xsl:template match="allee">
    <h1> Allée
	<xsl:value-of select="@numero"/>
    </h1>
    <hr/>
    <xsl:apply-templates/>
</xsl:template>


<xsl:template match="rayon">
    <h3>Rayon
	<xsl:value-of select="@numero"/>
    </h3>
    <table>
        <tr><xsl:template match="rayon">
    <h3> Rayon
        <xsl:value-of select="@numero">
    </h3>
            
            <th>Catégorie de l'ouvrage</th>
            <th>Titre</th>
            <th>Auteur</th>
            <th>Numéro</th>
        </tr>
    <xsl:apply-templates/>
    </table>
</xsl:template>

<xsl:template match="ouvrage">
    <tr>
        <td>
            <xsl:value-of select>
        </td>
    </tr>


</xsl:stylesheet>