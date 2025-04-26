<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="text"/>
<xsl:template match="/">"Version: <xsl:value-of select="report/header/@version"/>" "Date: <xsl:value-of select="report/header/@date"/>" "Time: <xsl:value-of select="report/header/@time"/>" "Root folder: <xsl:value-of select="report/header/@rootfolder"/>"
"CPU Info: <xsl:value-of select="report/header/@cpu"/>" "Physical memory (MB): <xsl:value-of select="report/header/@memory"/>" "Core setting: <xsl:value-of select="report/header/@core"/>" "Matrix compilation: <xsl:value-of select="report/header/@matrix"/>"

Mode Status "File name" "Exec time" "Reference exec time" "Iteration count" "Reference iteration count" "Point count" "Reference point count" "Comparison error"
<xsl:for-each select="report/testbench/testcase">
"<xsl:value-of select="@mode"/>" "<xsl:value-of select="@status"/>" "<xsl:value-of select="@circuit"/>" <xsl:value-of select="@exectime"/> <xsl:text> </xsl:text> <xsl:value-of select="@refexectime"/> <xsl:text> </xsl:text> <xsl:value-of select="@itercount"/> <xsl:text> </xsl:text> <xsl:value-of select="@refitercount"/> <xsl:text> </xsl:text> <xsl:value-of select="@points"/> <xsl:text> </xsl:text> <xsl:value-of select="@refpoints"/> <xsl:text> </xsl:text> <xsl:value-of select="@tolerror"/>
</xsl:for-each>
<xsl:choose>
<xsl:when test="report/footer/@success = 'True'">

Test finished.
</xsl:when>
<xsl:otherwise>

Test finished with errors.
</xsl:otherwise> 
</xsl:choose>
</xsl:template>
</xsl:stylesheet>
