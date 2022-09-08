<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
<xsl:template match="blibliotheque">
	<html>
            <heaad>
                <link href="blibliotheque_light.css" type="text/css" rel="stylesheet"></link>
            </heaad>
	<body>
		<xsl:apply-templates />
	</body>	
	</html>
</xsl:template>
<xsl:template match="allee">
    <h1>
	<xsl:value-of select="@numero"/>
    </h1>
	<table border="1">		
		<xsl:apply-templates />
	</table>
</xsl:template>
</xsl:stylesheet>