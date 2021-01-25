var chart;

chart = new Highcharts.chart({
    chart: {
	renderTo: "heightGrafica",
        type: 'spline',
        animation: Highcharts.svg,
        marginRight: 10,
    },

    time: {
        useUTC: false
    },

    title: {
        text: 'Height Sensor'
    },

    accessibility: {
        announceNewData: {
            enabled: true,
            minAnnounceInterval: 15000,
            announcementFormatter: function (allSeries, newSeries, newPoint) {
                if (newPoint) {
                    return 'New point added. Value: ' + newPoint.y;
                }
                return false;
            }
        }
    },

    xAxis: {
        type: 'datetime',
        tickPixelInterval: 150
    },

    yAxis: {
        title: {
            text: 'Height'
        },
        plotLines: [{
            value: 0,
            width: 1,
            color: '#808080'
        }]
    },

    tooltip: {
        headerFormat: '<b>{series.name}</b><br/>',
        pointFormat: '{point.x: %H:%M:%S}<br/>{point.y:.2f}'
    },

    legend: {
        enabled: false
    },

    exporting: {
        enabled: false
    },

    tooltip: {
	positioner: function () {
	        return {
        		// right aligned
                	x: this.chart.chartWidth - this.label.width,
	                y: 10 // align to title
        	};
        },
        borderWidth: 0,
        backgroundColor: 'none',
        pointFormat: '{point.y}',
        headerFormat: '',
        shadow: false,
	valueSuffix: ' ' + 'mm',
        style: {
        	fontSize: '18px'
        },
    },
    series: [{
        name: 'Height',
        data: []
    }]
});

var socket = new io.connect();
socket.on('connect', function() {
	  document.getElementById("status").innerHTML="Connected";

});

socket.on('Height', function(data) {
	var myData = parseFloat(data);
	height = myData;
	var grafica = chart.series[0];
	var point = [Date.now(), height];
	if(grafica.data.length == 40) grafica.addPoint(point,true,true);
	else grafica.addPoint(point,true);
});
