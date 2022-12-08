$(function ()
{
    var maWebsocket;
    // l'API WebSocket est-elle installee ?
    if (window.WebSocket)
    {
        // creation de la WebSocket
        maWebsocket = new WebSocket('ws://172.18.58.150:8888');

        //Gestion des evenements de la WebSocket
        maWebsocket.onopen = function ()
        {
            console.log("ouverture webSocket");
        };
        maWebsocket.onclose = function (event)
        {
            console.log("code de a la fermeture : " + event.code);
            console.log("raison de la fermeture : " + event.reason);
        };
        maWebsocket.onerror = function ()
        {
            console.log("erreur sur la webSocket");
        };
        maWebsocket.onmessage = function (donneesRecues)
        {
            console.log("reception de donnees : " + donneesRecues.data);
            console.log("origine : " + donneesRecues.origin);
            $(ladate).text("Réception des données : " + donneesRecues.data);
        };
    }
    $("#demande").click(function(){
        // envoyer la chaine "date" au serveur de WebSocket
       maWebsocket.send("date");
    });
});