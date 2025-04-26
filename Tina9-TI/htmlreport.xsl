<?xml version="1.0" encoding="utf-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="html"/>
<xsl:template match="/">
  <html>
  <head>
    <title>TINA Test Report</title>
    <style type="text/css">
      h1 {font-size: 30pt; color: maroon;}
      p.header {font-size: 14pt; color: navy;}
      p.test {font-size: 14pt; color: purple; font-style: italic;}
      p.reference {font-size: 14pt; color: green;}
      p.footer {font-size: 14pt;}
      P.buglist {text-indent: 1in;}
      span.error {font-size: 14pt; font-weight: bold; color: red;}
      th.test {font-style: italic;}
      th.reference {}
      td.test {font-style: italic;}
      td.reference {}
      #errorrow {color: red;}
    </style>
  </head>
  <body>
    <h1 align="center">TINA Test Report</h1>
    <p class="header"><span style="font-weight: bold;">Version: </span><xsl:value-of select="report/header/@version"/></p>
    <p class="header"><span style="font-weight: bold;"> Date: </span><xsl:value-of select="report/header/@date"/></p>
    <p class="header"><span style="font-weight: bold;"> Time: </span><xsl:value-of select="report/header/@time"/></p>
    <p class="header"><span style="font-weight: bold;"> Root folder: </span><xsl:value-of select="report/header/@rootfolder"/></p>
    <p class="header"><span style="font-weight: bold;">CPU Info: </span><xsl:value-of select="report/header/@cpu"/></p>
    <p class="header"><span style="font-weight: bold;"> Physical memory (MB): </span><xsl:value-of select="report/header/@memory"/></p>
    <p class="header"><span style="font-weight: bold;"> Core setting: </span><xsl:value-of select="report/header/@core"/></p>
    <p class="header"><span style="font-weight: bold;"> Matrix compilation: </span><xsl:value-of select="report/header/@matrix"/></p>
    <p style="page-break-before: always"></p>
    <xsl:for-each select="report/testbench/testcase">
    <table border="0">
      <tr>
        <th>Mode</th>
        <th>Status</th>
        <th>File name</th>
        <th class="test">Exec time (s)</th>
        <th class="reference">Reference exec time (s)</th>
        <th class="test">Iteration count</th>
        <th class="reference">Reference iteration count</th>
        <th class="test">Point count</th>
        <th class="reference">Reference point count</th>
        <th>Comparison error (%)</th>
      </tr>
      <tr>
        <xsl:if test="@success = 'False'">  
           <xsl:attribute name="id">errorrow</xsl:attribute>
        </xsl:if>
        <td align="left"><a><xsl:attribute name="name"><xsl:value-of select="@circuit"/></xsl:attribute></a><xsl:value-of select="@mode"/></td>
        <td align="left"><xsl:value-of select="@status"/></td>
        <td align="left"><xsl:value-of select="@circuit"/></td>
        <td class="test" align="center"><xsl:value-of select="@exectime"/></td>
        <td class="reference" align="center"><xsl:value-of select="@refexectime"/></td>
        <td class="test" align="center"><xsl:value-of select="@itercount"/></td>
        <td class="reference" align="center"><xsl:value-of select="@refitercount"/></td>
        <td class="test" align="center"><xsl:value-of select="@points"/></td>
        <td class="reference" align="center"><xsl:value-of select="@refpoints"/></td>
        <td align="center"><xsl:value-of select="@tolerror"/></td>
      </tr>
    </table>
    <center>
    <xsl:if test="@addpicture = 'True'">
    <p class="test">Tested</p>
    <img width="600" height="400">
      <xsl:attribute name="src">
        <xsl:value-of select="@picture"/>
      </xsl:attribute>
    </img>
    </xsl:if>
    <xsl:if test="@addrefpicture = 'True'">
    <p class="reference">Reference - (<span style="font-weight: bold;">Version: </span><xsl:value-of select="@refversion"/>)</p>
    <img width="600" height="400">
      <xsl:attribute name="src">
        <xsl:value-of select="@refpicture"/>
      </xsl:attribute>
    </img>
    </xsl:if>
    </center>
    <p style="page-break-before: always"></p>
    </xsl:for-each>
    <xsl:choose>
    <xsl:when test="report/footer/@success = 'True'">
    <p class="footer">Test finished.</p>
    </xsl:when>
    <xsl:otherwise>
    <p class="footer">Test finished <span class="error">with errors:</span></p>
    <xsl:for-each select="report/footer/buglist/bug">
    <p class="buglist"><a><xsl:attribute name="href"><xsl:value-of select="@circuit"/></xsl:attribute><xsl:value-of select="@circuit"/></a></p>   
    </xsl:for-each>
    </xsl:otherwise>
    </xsl:choose>
  </body>
  </html>
</xsl:template>
</xsl:stylesheet>
