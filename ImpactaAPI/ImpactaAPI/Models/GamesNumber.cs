using ImpactaAPI.Models;
using System.Collections.ObjectModel;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace ImpactaAPI.Models;

[Table("GamesNumbers")]
public class GamesNumber
{
    [Key]
    public int id { get; set; }

    [StringLength(64)]
    public string? machineName { get; set; }

    public DateTime dateTimePlay { get; set; }

    public int hitsTotal { get; set; }
    public int totalGames { get; set; }
}
