using ImpactaAPI.Models;
using System.Collections.ObjectModel;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace ImpactaAPI.Models;

[Table("HitsNumbers")]
public class HitsNumber
{
    [Key]
    public int id { get; set; }

    [StringLength(64)]
    public string? machineName { get; set; }

    public DateTime dateTimePlay { get; set; }

    public int hitsTotal { get; set; }
}
