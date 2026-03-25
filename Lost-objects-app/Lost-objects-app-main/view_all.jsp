<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.sql.*" %>
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Εμφάνιση Αντικειμένων</title>
    <style>
        /* Διαμόρφωση σελίδας*/
        body {
            color: #ffffff; 
            font-family: sans-serif;
            text-align: center;
        }

        /* Στυλ Πίνακα */
        table {
            border-collapse: collapse;
            width: 100%;
            border: 1px solid #d4a74a;
            margin-bottom: 25px;
        }

        /*Στυλ πρωτης γραμμης πινακα και δεδομενων*/
        th, td {
            border: 1px solid #4a4a3a;
            padding: 12px;
            text-align: center;
        }


        /* Στυλ για το κουμπί Διαγραφή */
        .btn-delete {
            background-color: #ff0000; 
        }

        .error-msg { color: #ff3333; font-weight: bold; margin-bottom: 15px; }
        a { color: #4a90e2; text-decoration: none; display: block; margin-top: 20px; }/*Στυλ συνδεσμου που παει στην αρχικη οθονη*/
        
    </style>
</head>

<body>
    <h1>Εμφάνιση Αντικειμένων</h1>
    
    <%
        // Διαβαζουμε τη μεταβλητη error, αν υπαρχει
        String error = request.getParameter("error");
        if (error != null) {
    %>
        <p class="error-msg">Πρόβλημα με την διαγραφή: <%= error %></p>
    <% } %>

    <table>
        <tr>
            <th>Κωδικός</th> 
            <th>Περιγραφή</th>
            <th>Ευρών</th>
            <th>Τοποθεσία</th>
            <th>Ενέργεια</th>
        </tr>
        <%
            //Βρίσκουμε την πραγματική διαδρομή του αρχείου της βάσης στον server
            String dbPath = getServletContext().getRealPath("/WEB-INF/laf.db");
            String dbURL = "jdbc:sqlite:" + dbPath;

            try {
                Class.forName("org.sqlite.JDBC");  //Φόρτωση του Driver της SQLite
                Connection conn = DriverManager.getConnection(dbURL); //Άνοιγμα της σύνδεσης με τη βάση
                Statement stmt = conn.createStatement(); //Δημιουργία αντικειμένου για την εκτέλεση της εντολής SQL
                ResultSet rs = stmt.executeQuery("SELECT * FROM LostAndFound"); //Εκτέλεση του ερωτήματος SELECT για να πάρουμε όλα τα δεδομένα

                while (rs.next()) {
                    int id = rs.getInt("id"); // Παίρνουμε το id του αντικειμένου
        %>
                <tr>
                    <td><%= id %></td>
                    <td><%= rs.getString("description") %></td>
                    <td><%= rs.getString("finder") %></td>
                    <td><%= rs.getString("location") %></td>
                    <td>
                        <%-- Φόρμα που στέλνει το id στον Controller για να διαγραφεί το συγκεκριμένο αντικείμενο --%>
                        <form action="controller" method="POST" style="margin:0;">
                            <input type="hidden" name="action" value="delete">  <%-- Κρυφό πεδίο για την ενέργεια (delete) --%>
                            <input type="hidden" name="id" value="<%= id %>">   <%-- Κρυφό πεδίο με το ID του αντικειμένου --%>
                            <input type="submit" value="Διαγραφή" class="btn-delete">
                        </form>
                    </td>
                </tr>
        <%
                }
             // Κλείσιμο των πόρων για εξοικονόμηση μνήμης
                rs.close();
                stmt.close();
                conn.close();
            } catch (Exception e) {
            	// Εμφάνιση σφάλματος αν υπάρξει error
                out.println("<tr><td colspan='5' style='color:red;'>Σφάλμα: " + e.getMessage() + "</td></tr>");
            }
        %>
    </table>

    <a href="index.jsp">Επιστροφή στην Αρχική Σελίδα</a>

<p style="margin-top: 25px;">Δημιουργήθηκε από την Γεωρλια </p>

</body>
</html>
