<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

    <xsl:template match="/">      
        <html>
        <body>
            <h1>Book List</h1>
            <ul>
                <xsl:for-each select="library/book">  
                    <li>
                        <strong>Title:</strong> <xsl:value-of select="title"/>
                        <br/>
                        <strong>Author:</strong> <xsl:value-of select="author"/>
                    </li>
                </xsl:for-each>
            </ul>
        </body>
        </html>
    </xsl:template>

</xsl:stylesheet>